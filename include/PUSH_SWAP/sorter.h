/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:47:26 by htsang            #+#    #+#             */
/*   Updated: 2023/03/23 15:13:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "PUSH_SWAP/stack.h"
# include "PUSH_SWAP/sorter/instructor.h"
# include "PUSH_SWAP/sorter/triangle_planner.h"
# include "PUSH_SWAP/sorter/triangle_maker.h"

typedef struct s_push_swap_sorter
{
	t_push_swap_2stacks				two_stacks;
	t_push_swap_triangles_planner	planner;
	t_push_swap_instructor			instructor;
}               t_push_swap_sorter;

t_push_swap_error_code	create_all_triangles(t_push_swap_sorter *sorter);

#endif