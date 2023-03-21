/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation_priority_mover copy.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:34:35 by htsang            #+#    #+#             */
/*   Updated: 2023/03/21 20:56:37 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

t_push_swap_emulation_priority_location	get_priority_location(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority highest_priority)
{
	unsigned int	front_size;
	unsigned int	i;

	front_size = triangle_maker->triangle_size - \
		triangle_maker->emulated_stack_a_rear_size;
	i = 0;
	while (i < front_size)
	{
		if (get_emulation_priority_by_index(i, triangle_maker, STACK_A) == \
				highest_priority)
			return (PRIORITY_AT_FRONT);
		i++;
	}
	return (PRIORITY_AT_REAR);
}

int	priority_decreases_after_index_2(t_push_swap_triangle_maker *triangle_maker)
{
	t_push_swap_emulation_priority	priority;
	unsigned int					i;

	i = 2;
	while (i < triangle_maker->emulated_stack_a_front_size)
	{
		priority = get_emulation_priority_by_index(i, triangle_maker, STACK_A);
		if (priority > triangle_maker->highest_priority)
			return (0);
		
		i++;
	}
	return (1);
}
