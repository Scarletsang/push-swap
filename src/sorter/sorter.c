/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:38:05 by htsang            #+#    #+#             */
/*   Updated: 2023/04/27 16:17:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

int	sorter_free(t_push_swap_sorter *sorter)
{
	two_stacks_free(&sorter->two_stacks);
	if (sorter->planner.triangles_size)
		free(sorter->planner.triangles_size);
	instruction_list_free_all(sorter->instructor.cost);
	return (EXIT_FAILURE);
}

void	sorter_init(t_push_swap_sorter *sorter)
{
	sorter->two_stacks.stack_a.elements = NULL;
	sorter->two_stacks.stack_b.elements = NULL;
	sorter->planner.triangles_size = NULL;
	sorter->instructor.cost = NULL;
}

t_push_swap_error_code	sorter_create_last_triangle_on_stack_a(\
t_push_swap_sorter *sorter, t_push_swap_instructor	*emulation_instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	unsigned int				last_triangle_index;
	t_push_swap_triangle_shape	triangle_shape;

	last_triangle_index = sorter->planner.total_triangles - 1;
	triangle_shape = triangles_planner_calculate_triangle_shape(\
		last_triangle_index, sorter->planner.total_triangles, \
			sorter->planner.merge_dimension);
	if (sorter->planner.merge_dimension > 0)
		triangle_shape = triangle_shape_switch(triangle_shape);
	triangle_maker_update(triangle_maker, \
		sorter->planner.triangles_size[last_triangle_index], triangle_shape);
	triangle_maker_emulate_two_stacks(triangle_maker, &sorter->two_stacks);
	if (triangle_maker_create_triangle_on_stack_a(triangle_maker, \
		emulation_instructor))
		return (FAILURE);
	instructor_concat(&sorter->instructor, emulation_instructor);
	instructor_execute_unexecuted(&sorter->instructor);
	return (SUCCESS);
}

t_push_swap_error_code	sorter_create_all_triangles_on_stack_b(\
t_push_swap_sorter *sorter, t_push_swap_instructor	*emulation_instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	unsigned int				triangle_index;

	triangle_index = 0;
	while (triangle_index < (sorter->planner.total_triangles - 1))
	{
		triangle_maker_update(triangle_maker, \
			sorter->planner.triangles_size[triangle_index], \
			triangles_planner_calculate_triangle_shape(\
				triangle_index, sorter->planner.total_triangles, \
				sorter->planner.merge_dimension));
		triangle_maker_emulate_two_stacks(triangle_maker, &sorter->two_stacks);
		if (triangle_maker_create_triangle_on_stack_b(triangle_maker, \
			emulation_instructor))
			return (FAILURE);
		instructor_concat(&sorter->instructor, emulation_instructor);
		instructor_execute_unexecuted(&sorter->instructor);
		triangle_index++;
	}
	return (SUCCESS);
}

t_push_swap_error_code	sorter_create_all_triangles(t_push_swap_sorter *sorter)
{
	t_push_swap_instructor		emulation_instructor;
	t_push_swap_triangle_maker	triangle_maker;

	if (triangle_maker_init(&emulation_instructor, &triangle_maker))
		return (FAILURE);
	if (sorter_create_all_triangles_on_stack_b(sorter, &emulation_instructor, \
			&triangle_maker) || \
		sorter_create_last_triangle_on_stack_a(sorter, &emulation_instructor, \
			&triangle_maker))
	{
		instruction_list_free_all(emulation_instructor.cost);
		two_stacks_free(&triangle_maker.emulation);
		return (FAILURE);
	}
	free(emulation_instructor.cost);
	two_stacks_free(&triangle_maker.emulation);
	return (SUCCESS);
}
