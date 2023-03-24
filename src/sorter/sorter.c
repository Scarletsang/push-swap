/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:38:05 by htsang            #+#    #+#             */
/*   Updated: 2023/03/24 14:25:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

t_push_swap_error_code	create_last_triangle_on_stack_a(\
t_push_swap_sorter *sorter, t_push_swap_instructor	*emulation_instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	unsigned int				last_triangle_index;
	t_push_swap_triangle_shape	triangle_shape;

	last_triangle_index = sorter->planner.total_triangles - 1;
	triangle_shape = get_triangle_shape(\
		last_triangle_index, sorter->planner.total_triangles, \
			sorter->planner.triangle_dimension);
	if (sorter->planner.triangle_dimension > 0)
		triangle_shape = switch_triangle_shape(triangle_shape);
	prepare_emulation(triangle_maker, \
		sorter->planner.triangles[last_triangle_index], triangle_shape);
	emulate_two_stacks(triangle_maker, &sorter->two_stacks);
	if (create_triangle_on_stack_a(emulation_instructor, triangle_maker))
		return (FAILURE);
	concat_instructor(&sorter->instructor, emulation_instructor);
	execute_unexecuted_instructions(&sorter->instructor);
	return (SUCCESS);
}

t_push_swap_error_code	create_all_triangles_on_stack_b(\
t_push_swap_sorter *sorter, t_push_swap_instructor	*emulation_instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	unsigned int				triangle_index;

	triangle_index = 0;
	while (triangle_index < (sorter->planner.total_triangles - 1))
	{
		prepare_emulation(triangle_maker, \
			sorter->planner.triangles[triangle_index], get_triangle_shape(\
				triangle_index, sorter->planner.total_triangles, \
				sorter->planner.triangle_dimension));
		emulate_two_stacks(triangle_maker, &sorter->two_stacks);
		if (create_triangle_on_stack_b(emulation_instructor, triangle_maker))
			return (FAILURE);
		concat_instructor(&sorter->instructor, emulation_instructor);
		execute_unexecuted_instructions(&sorter->instructor);
		triangle_index++;
	}
	return (SUCCESS);
}

t_push_swap_error_code	create_all_triangles(t_push_swap_sorter *sorter)
{
	t_push_swap_instructor		emulation_instructor;
	t_push_swap_triangle_maker	triangle_maker;

	if (init_triangle_maker(&emulation_instructor, &triangle_maker))
		return (FAILURE);
	if (create_all_triangles_on_stack_b(sorter, &emulation_instructor, \
			&triangle_maker) || \
		create_last_triangle_on_stack_a(sorter, &emulation_instructor, \
			&triangle_maker))
	{
		free_instruction_list(emulation_instructor.cost);
		free_two_stacks(&triangle_maker.emulation);
		return (FAILURE);
	}
	free(emulation_instructor.cost);
	free_two_stacks(&triangle_maker.emulation);
	return (SUCCESS);
}
