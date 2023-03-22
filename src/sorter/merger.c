/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merger.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:38:20 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 15:22:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

void	push_one_third_of_triangles_to(t_push_swap_sorter *sorter, \
t_push_swap_stack_indicator to)
{
	unsigned int			amount_of_elements_to_push;
	unsigned int			index;

	index = (sorter->planner.total_triangles / 3) - 1;
	amount_of_elements_to_push = 0;
	while (index > 0)
	{
		amount_of_elements_to_push += sorter->planner.triangles[index--];
	}
	amount_of_elements_to_push += sorter->planner.triangles[index];
	amount_of_elements_to_push -= 2;
	if (to == STACK_A)
		return (add_instructions_n_times(&sorter->instructor, PA, \
			amount_of_elements_to_push));
	return (add_instructions_n_times(&sorter->instructor, PB, \
		amount_of_elements_to_push));
}

t_push_swap_error_code	merge_one_triangle(t_push_swap_sorter *sorter, \
t_push_swap_triangle_size size, t_push_swap_triangle_shape shape, \
t_push_swap_stack_indicator to)
{
	
}
