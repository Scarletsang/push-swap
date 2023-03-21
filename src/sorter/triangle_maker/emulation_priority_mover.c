/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation_priority_mover.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:34:35 by htsang            #+#    #+#             */
/*   Updated: 2023/03/21 20:57:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

t_push_swap_emulation_priority_location	get_priority_location(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority highest_priority);

int										priority_decreases_after_index_2(\
t_push_swap_triangle_maker *triangle_maker);

static t_push_swap_emulation_priority_location	get_priority_location(\
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

static int	priority_decreases_after_index_2(\
t_push_swap_triangle_maker *triangle_maker)
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

static t_push_swap_error_code	priority_at_rear(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount, \
t_push_swap_emulation_priority_location forced_search)
{
	if (get_emulation_priority_by_index(0, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority)
		return (front1rear1(sorter, triangle_maker));
	if (rear1(sorter, triangle_maker))
		return (FAILURE);
	return (move_priority_elements(sorter, triangle_maker, priority_amount - 1, \
		forced_search));
}

static t_push_swap_error_code	priority_at_front(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount, \
t_push_swap_emulation_priority_location forced_search)
{
	if (get_emulation_priority_by_index(1, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority)
		return (front2(sorter, triangle_maker));
	if (emulate_instruction(sorter, triangle_maker, PB))
		return (FAILURE);
	return (move_priority_elements(sorter, triangle_maker, priority_amount - 1, \
		forced_search));
}

static t_push_swap_error_code	forced_search_at_front(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount, \
t_push_swap_emulation_priority_location forced_search)
{
	if ((get_emulation_priority_by_index(1, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority) && \
		priority_decreases_after_index_2(triangle_maker))
	{
		if (emulate_instruction(sorter, triangle_maker, SA))
			return (FAILURE);
		return (move_priority_elements(sorter, triangle_maker, priority_amount, \
			PRIORITY_AT_FRONT));
	}
	if (emulate_instruction(sorter, triangle_maker, RA))
		return (FAILURE);
	return (move_priority_elements(sorter, triangle_maker, priority_amount, \
		PRIORITY_AT_FRONT));
}

static t_push_swap_error_code	forced_search_at_rear(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount, \
t_push_swap_emulation_priority_location forced_search)
{
	if (emulate_instruction(sorter, triangle_maker, RRA))
		return (FAILURE);
	return (move_priority_elements(sorter, triangle_maker, priority_amount, \
		PRIORITY_AT_REAR));
}

t_push_swap_error_code	move_priority_elements(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount, \
t_push_swap_emulation_priority_location forced_search)
{
	if (priority_amount == 0)
		return (SUCCESS);
	if (get_emulation_priority_by_index(-1, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority)
		return (priority_at_rear(sorter, triangle_maker, priority_amount, \
			forced_search));
	if (get_emulation_priority_by_index(0, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority)
		return (priority_at_front(sorter, triangle_maker, priority_amount, \
			forced_search));
	if (forced_search == PRIORITY_AT_FRONT)
		return (forced_search_at_front(sorter, triangle_maker, priority_amount, \
			forced_search));
	if (forced_search == PRIORITY_AT_REAR)
		return (forced_search_at_rear(sorter, triangle_maker, priority_amount, \
			forced_search));
	return (move_priority_elements(sorter, triangle_maker, priority_amount, \
		get_priority_location(triangle_maker, priority_amount)));
}
