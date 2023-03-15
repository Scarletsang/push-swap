/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 08:42:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/15 10:15:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

unsigned int	calculate_cost(t_push_swap_sorter *sorter, \
t_push_swap_triangle_size triangle_size, t_push_swap_triangle_shape shape)
{
	unsigned int				cost;
	unsigned int				stack_rear_size;
	t_push_swap_emulation_group	biggest_group;

	stack_rear_size = sorter->emulation_range_from * -1;
	cost = stack_rear_size * 2;
	biggest_group = triangle_size / 2;
	while ()
	{
		
	}
}

t_push_swap_emulation_range_from	calculate_best_rear_size(\
t_push_swap_sorter *sorter, t_push_swap_2stacks *two_stacks, \
t_push_swap_triangle_size triangle_size, t_push_swap_triangle_shape shape)
{
	t_push_swap_emulation_range_from	from;
	unsigned int						best_cost;
	unsigned int						current_cost;

	if (triangle_size < TRIANGLE_SIZE_3)
		from = RANGE_FROM_0;
	else
		from = RANGE_FROM_MINUS_3 + (TRIANGLE_SIZE_6 - triangle_size);
	emulate_two_stacks(sorter, two_stacks, from, triangle_size);
	best_cost = calculate_cost(sorter, triangle_size, shape);
	while (--from > RANGE_FROM_0)
	{
		emulate_two_stacks(sorter, two_stacks, from, triangle_size);
		current_cost = calculate_cost(sorter, triangle_size, shape);
		if (current_cost < best_cost)
			best_cost = current_cost;
	}
	return (from + 1);
}
