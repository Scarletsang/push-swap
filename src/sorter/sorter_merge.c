/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_merge.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:36:44 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:42:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

static t_push_swap_error_code	sorter_push_one_third_of_triangles(\
t_push_swap_sorter *sorter)
{
	unsigned int			amount_of_elements_to_push;
	unsigned int			index;

	index = sorter->planner.total_triangles - \
		(sorter->planner.total_triangles / 3);
	amount_of_elements_to_push = 0;
	while (index < sorter->planner.total_triangles)
	{
		amount_of_elements_to_push += sorter->planner.triangles_size[index];
		index++;
	}
	amount_of_elements_to_push -= sorter->merger.destination_stack->size;
	if (sorter->merger.destination_stack == &sorter->two_stacks.stack_a)
		return (instructor_add_n_times(&sorter->instructor, PA, \
			amount_of_elements_to_push));
	return (instructor_add_n_times(&sorter->instructor, PB, \
		amount_of_elements_to_push));
}

static t_push_swap_error_code	sorter_push_merge_target(\
t_push_swap_sorter *sorter, t_push_swap_merge_target target)
{
	if (target == UNKNOWN_MERGE_TARGET)
		return (SUCCESS);
	sorter->merger.triangle_sizes[target]--;
	if (sorter->merger.destination_stack == &sorter->two_stacks.stack_a)
	{
		if (target == TRIANGLE_AT_DESTINATION)
			return (instructor_add(&sorter->instructor, RRA));
		if (target == TRIANGLE_AT_SOURCE_REAR)
			return (instructor_add_multiple(&sorter->instructor, \
				(t_push_swap_instruction[3]){2, RRB, PA}));
		return (instructor_add(&sorter->instructor, PA));
	}
	if (target == TRIANGLE_AT_DESTINATION)
		return (instructor_add(&sorter->instructor, RRB));
	if (target == TRIANGLE_AT_SOURCE_REAR)
		return (instructor_add_multiple(&sorter->instructor, \
			(t_push_swap_instruction[3]){2, RRA, PB}));
	return (instructor_add(&sorter->instructor, PB));
}

static t_push_swap_error_code	sorter_merge_one_element(\
t_push_swap_sorter *sorter, t_push_swap_triangle_shape shape)
{
	t_push_swap_merge_target	compare_target;
	t_push_swap_merge_target	merge_target;
	int							priority_element;
	int							current_element;

	compare_target = merger_get_first_nonempty_merge_target(&sorter->merger);
	merge_target = compare_target;
	priority_element = merger_get_merge_target(&sorter->merger, compare_target);
	while (compare_target < 3)
	{
		current_element = merger_get_merge_target(&sorter->merger, \
			compare_target);
		if ((sorter->merger.triangle_sizes[compare_target] != 0) && \
			(shape(priority_element, current_element)))
		{
			priority_element = current_element;
			merge_target = compare_target;
		}
		compare_target++;
	}
	return (sorter_push_merge_target(sorter, merge_target));
}

static t_push_swap_error_code	sorter_merge_triangles(\
t_push_swap_sorter *sorter)
{
	unsigned int				new_total_triangles;
	unsigned int				triangle_index;
	t_push_swap_triangle_shape	triangle_shape;

	new_total_triangles = sorter->planner.total_triangles / 3;
	triangle_index = 0;
	while (triangle_index < new_total_triangles)
	{
		merger_update(&sorter->merger, &sorter->planner, triangle_index);
		triangle_shape = calculate_triangle_shape(triangle_index, \
			new_total_triangles, sorter->planner.merge_dimension);
		while (merger_get_first_nonempty_merge_target(&sorter->merger) != \
			UNKNOWN_MERGE_TARGET)
		{
			if (sorter_merge_one_element(sorter, triangle_shape))
				return (FAILURE);
		}
		triangle_index++;
	}
	return (SUCCESS);
}

t_push_swap_error_code	sorter_merge_triangles_till_sorted(\
t_push_swap_sorter *sorter)
{
	unsigned int	i;

	i = 0;
	sorter->instructor.automatic_execute = 1;
	while (i < sorter->planner.merge_dimension)
	{
		if (sorter_push_one_third_of_triangles(sorter) || \
			sorter_merge_triangles(sorter))
			return (FAILURE);
		merger_swap_stacks(&sorter->merger);
		merge_triangles_planner(&sorter->planner);
		i++;
	}
	if (sorter->two_stacks.stack_b.size != 0)
		return (instructor_add_n_times(&sorter->instructor, PA, \
			sorter->two_stacks.stack_b.size));
	return (SUCCESS);
}
