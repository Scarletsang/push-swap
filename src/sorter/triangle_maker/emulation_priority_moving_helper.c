/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation_priority_moving_helper.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:34:35 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 07:10:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

t_push_swap_emulation_priority_location	emulator_search_priority_location(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority highest_priority)
{
	unsigned int	i;

	i = 0;
	while (i < triangle_maker->emulated_stack_a_front_size)
	{
		if (emulator_get_priority_by_index(triangle_maker, i) == \
				highest_priority)
			return (PRIORITY_AT_FRONT);
		i++;
	}
	return (PRIORITY_AT_REAR);
}

int	emulator_is_priority_decrease_after_sa(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority target_priority)
{
	t_push_swap_emulation_priority	priority;
	unsigned int					i;

	i = 2;
	while (i < triangle_maker->emulated_stack_a_front_size)
	{
		priority = emulator_get_priority_by_index(triangle_maker, i);
		if (priority > target_priority)
			return (0);
		i++;
	}
	return (1);
}
