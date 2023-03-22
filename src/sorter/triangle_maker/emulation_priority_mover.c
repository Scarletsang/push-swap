/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation_priority_mover.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:34:35 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 02:51:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

t_push_swap_emulation_priority_location	get_priority_location(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority highest_priority);

int										priority_decreases_after_index_2(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority target_priority);

static t_push_swap_error_code	priority_at_rear(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount, \
t_push_swap_emulation_priority_location forced_search)
{
	if (get_emulation_priority_by_index(0, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority)
		return (front1rear1(instructor, triangle_maker));
	if (rear1(instructor, triangle_maker))
		return (FAILURE);
	return (move_priority_elements(instructor, triangle_maker, priority_amount - 1, \
		forced_search));
}

static t_push_swap_error_code	priority_at_front(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount, \
t_push_swap_emulation_priority_location forced_search)
{
	if (get_emulation_priority_by_index(1, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority)
		return (front2(instructor, triangle_maker));
	if (emulate_instruction(instructor, triangle_maker, PB))
		return (FAILURE);
	return (move_priority_elements(instructor, triangle_maker, priority_amount - 1, \
		forced_search));
}

static t_push_swap_error_code	forced_search_at_front(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount)
{
	if ((get_emulation_priority_by_index(1, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority) && \
		priority_decreases_after_index_2(triangle_maker, \
			get_emulation_priority_by_index(0, triangle_maker, STACK_A)))
	{
		if (emulate_instruction(instructor, triangle_maker, SA))
			return (FAILURE);
		return (move_priority_elements(instructor, triangle_maker, priority_amount, \
			PRIORITY_AT_FRONT));
	}
	if (emulate_instruction(instructor, triangle_maker, RA))
		return (FAILURE);
	return (move_priority_elements(instructor, triangle_maker, priority_amount, \
		PRIORITY_AT_FRONT));
}

static t_push_swap_error_code	forced_search_at_rear(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount)
{
	if (emulate_instruction(instructor, triangle_maker, RRA))
		return (FAILURE);
	return (move_priority_elements(instructor, triangle_maker, priority_amount, \
		PRIORITY_AT_REAR));
}

t_push_swap_error_code	move_priority_elements(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount, \
t_push_swap_emulation_priority_location forced_search)
{
	if (priority_amount == 0)
	{
		if (get_element_by_index(&triangle_maker->emulation.stack_b, 0) > \
			get_element_by_index(&triangle_maker->emulation.stack_b, 1))
			return (emulate_instruction(instructor, triangle_maker, SB));
		return (SUCCESS);
	}
	if (get_emulation_priority_by_index(-1, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority)
		return (priority_at_rear(instructor, triangle_maker, priority_amount, \
			forced_search));
	if (get_emulation_priority_by_index(0, triangle_maker, STACK_A) == \
		triangle_maker->highest_priority)
		return (priority_at_front(instructor, triangle_maker, priority_amount, \
			forced_search));
	if (forced_search == PRIORITY_AT_FRONT)
		return (forced_search_at_front(instructor, triangle_maker, priority_amount));
	if (forced_search == PRIORITY_AT_REAR)
		return (forced_search_at_rear(instructor, triangle_maker, priority_amount));
	return (move_priority_elements(instructor, triangle_maker, priority_amount, \
		get_priority_location(triangle_maker, priority_amount)));
}
