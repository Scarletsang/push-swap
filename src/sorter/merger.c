/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:38:20 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:09:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

void	merger_swap_stacks(t_push_swap_merger *merger)
{
	t_push_swap_stack	*tmp;

	tmp = merger->destination_stack;
	merger->destination_stack = merger->source_stack;
	merger->source_stack = tmp;
}

int	merger_get_merge_target(t_push_swap_merger *merger, \
t_push_swap_merge_target target)
{
	if (target == TRIANGLE_AT_DESTINATION)
		return (stack_get_element_by_index(merger->destination_stack, -1));
	if (target == TRIANGLE_AT_SOURCE_REAR)
		return (stack_get_element_by_index(merger->source_stack, -1));
	return (stack_get_element_by_index(merger->source_stack, 0));
}

t_push_swap_merge_target	merger_get_first_nonempty_merge_target(\
t_push_swap_merger *merger)
{
	t_push_swap_merge_target	merge_target;

	merge_target = TRIANGLE_AT_DESTINATION;
	while (merge_target < 3)
	{
		if (merger->triangle_sizes[merge_target] > 0)
			return (merge_target);
		merge_target++;
	}
	return (UNKNOWN_MERGE_TARGET);
}

void	merger_update(t_push_swap_merger *merger, \
t_push_swap_triangles_planner *planner, unsigned int triangle_index)
{
	unsigned int	last_triangle_index;

	last_triangle_index = planner->total_triangles - 1 - triangle_index;
	merger->triangle_sizes[TRIANGLE_AT_DESTINATION] = \
		planner->triangles_size[last_triangle_index];
	merger->triangle_sizes[TRIANGLE_AT_SOURCE_FRONT] = \
		planner->triangles_size[last_triangle_index - \
		(planner->total_triangles / 3)];
	merger->triangle_sizes[TRIANGLE_AT_SOURCE_REAR] = \
		planner->triangles_size[triangle_index];
}

void	merger_init(t_push_swap_merger *merger, \
t_push_swap_2stacks *two_stacks)
{
	merger->destination_stack = &two_stacks->stack_a;
	merger->source_stack = &two_stacks->stack_b;
}
