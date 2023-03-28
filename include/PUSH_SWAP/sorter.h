/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:47:26 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:36:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "PUSH_SWAP/stack.h"
# include "PUSH_SWAP/sorter/instructor.h"
# include "PUSH_SWAP/sorter/triangle_planner.h"
# include "PUSH_SWAP/sorter/triangle_maker.h"

////////////////////////////////////
////////     The merger     ////////
////////////////////////////////////

typedef enum e_push_swap_merge_target
{
	TRIANGLE_AT_DESTINATION = 0,
	TRIANGLE_AT_SOURCE_FRONT,
	TRIANGLE_AT_SOURCE_REAR,
	UNKNOWN_MERGE_TARGET
}				t_push_swap_merge_target;

typedef struct s_push_swap_merger
{
	t_push_swap_triangle_size	triangle_sizes[3];
	t_push_swap_stack			*destination_stack;
	t_push_swap_stack			*source_stack;
}				t_push_swap_merger;

void						merger_swap_stacks(t_push_swap_merger *merger);

int							merger_get_merge_target(t_push_swap_merger *merger, \
t_push_swap_merge_target target);

t_push_swap_merge_target	merger_get_first_nonempty_merge_target(\
t_push_swap_merger *merger);

void						merger_update(t_push_swap_merger *merger, \
t_push_swap_triangles_planner *planner, unsigned int triangle_index);

void						merger_init(t_push_swap_merger *merger, \
t_push_swap_2stacks *two_stacks);

////////////////////////////////////
////////     The sorter     ////////
////////////////////////////////////

typedef struct s_push_swap_sorter
{
	t_push_swap_2stacks				two_stacks;
	t_push_swap_triangles_planner	planner;
	t_push_swap_instructor			instructor;
	t_push_swap_merger				merger;
}				t_push_swap_sorter;

t_push_swap_error_code		sorter_create_all_triangles(\
t_push_swap_sorter *sorter);

t_push_swap_error_code		sorter_merge_triangles_till_sorted(\
t_push_swap_sorter *sorter);

int							sorter_free(t_push_swap_sorter *sorter);

#endif