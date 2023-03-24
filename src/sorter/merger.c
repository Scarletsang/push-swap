/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:38:20 by htsang            #+#    #+#             */
/*   Updated: 2023/03/24 14:28:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

void	swap_merge_stack(t_push_swap_merger *merger)
{
	t_push_swap_stack	*tmp;

	tmp = merger->destination_stack;
	merger->destination_stack = merger->source_stack;
	merger->source_stack = tmp;
}

int	get_merge_target(t_push_swap_merger *merger, \
t_push_swap_merge_target target)
{
	if (target == TRIANGLE_AT_DESTINATION)
		return (get_element_by_index(merger->destination_stack, -1));
	if (target == TRIANGLE_AT_SOURCE_REAR)
		return (get_element_by_index(merger->source_stack, -1));
	return (get_element_by_index(merger->source_stack, 0));
}

t_push_swap_merge_target	get_first_nonempty_merge_target(\
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

void	prepare_merging(t_push_swap_merger *merger, \
t_push_swap_triangles_planner *planner, unsigned int triangle_index)
{
	unsigned int	last_triangle_index;

	last_triangle_index = planner->total_triangles - 1 - triangle_index;
	merger->triangle_sizes[TRIANGLE_AT_DESTINATION] = \
		planner->triangles[last_triangle_index];
	merger->triangle_sizes[TRIANGLE_AT_SOURCE_FRONT] = \
		planner->triangles[last_triangle_index - \
		(planner->total_triangles / 3)];
	merger->triangle_sizes[TRIANGLE_AT_SOURCE_REAR] = \
		planner->triangles[triangle_index];
}

void	init_merger(t_push_swap_sorter *sorter)
{
	sorter->merger.destination_stack = &sorter->two_stacks.stack_a;
	sorter->merger.source_stack = &sorter->two_stacks.stack_b;
}
