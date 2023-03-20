/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_priority_elements.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 19:03:04 by htsang            #+#    #+#             */
/*   Updated: 2023/03/20 23:43:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

static int	priority_decreases_after(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority target_priority, \
unsigned int emulated_stack_a_front_size)
{
	t_push_swap_emulation_priority	priority;
	unsigned int					i;

	i = 1;
	while (i < emulated_stack_a_front_size)
	{
		priority = get_emulation_priority_by_index(i, triangle_maker, STACK_A);
		if (priority > target_priority)
			return (0);
		
		i++;
	}
	return (1);
}

static t_push_swap_error_code	push_priority_from_front_logic(\
t_push_swap_sorter *sorter, t_push_swap_triangle_maker *triangle_maker, \
unsigned int index, unsigned int emulated_stack_a_front_size)
{
	if (index > 0)
	{
		triangle_maker->emulated_stack_a_rear_size += index;
		emulated_stack_a_front_size -= index;
		if (add_instructions_n_times(sorter, RA, index))
			return (FAILURE);
		if (priority_decreases_after(triangle_maker, \
			get_emulation_priority_by_index(-1, triangle_maker, STACK_A), \
			emulated_stack_a_front_size))
		{
			triangle_maker->emulated_stack_a_rear_size--;
			edit_last_instruction(sorter, SA);
		}
	}
	return (add_instruction(sorter, PB));
}

t_push_swap_error_code	push_priority_from_front(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority highest_priority)
{
	unsigned int	i;
	unsigned int	emulated_stack_a_front_size;

	emulated_stack_a_front_size = triangle_maker->triangle_size - \
		triangle_maker->emulated_stack_a_rear_size;
	i = 0;
	while (i < emulated_stack_a_front_size)
	{
		if (get_emulation_priority_by_index(i, triangle_maker, STACK_A) == \
			highest_priority)
		{
			if (push_priority_from_front_logic(sorter, triangle_maker, i, \
				emulated_stack_a_front_size))
				return (FAILURE);
			triangle_maker->triangle_size--;
			triangle_maker->priority_location = PRIORITY_AT_FRONT;
			return (SUCCESS);
		}
		i++;
	}
	triangle_maker->priority_location = UNKNOWN_PRIORITY_LOCATION;
	return (SUCCESS);
}

t_push_swap_error_code	push_priority_from_rear(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority highest_priority)
{
	unsigned int	i;

	i = 1;
	while (i <= triangle_maker->emulated_stack_a_rear_size)
	{
		if (get_emulation_priority_by_index(-i, triangle_maker, STACK_A) == \
			highest_priority)
		{
			if (add_instructions_n_times(sorter, RRA, i - 1) || \
				rear1(sorter, triangle_maker))
				return (FAILURE);
			triangle_maker->emulated_stack_a_rear_size -= i;
			triangle_maker->triangle_size--;
			triangle_maker->priority_location = PRIORITY_AT_REAR;
			return (SUCCESS);
		}
		i++;
	}
	triangle_maker->priority_location = UNKNOWN_PRIORITY_LOCATION;
	return (SUCCESS);
}
