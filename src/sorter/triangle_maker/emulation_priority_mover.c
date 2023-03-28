/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation_priority_mover.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 17:34:35 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 07:02:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

t_push_swap_emulation_priority_location	emulator_search_priority_location(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority highest_priority);

int										emulator_is_priority_decrease_after_sa(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority target_priority);

static t_push_swap_error_code	emulator_push_priority_from_rear(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instructor *instructor, unsigned int priority_amount)
{
	if (emulator_get_priority_by_index(triangle_maker, 0) == \
		triangle_maker->highest_priority)
		return (triangle_maker_formula_front1rear1(triangle_maker, instructor));
	if (triangle_maker_formula_rear1(triangle_maker, instructor))
		return (FAILURE);
	return (emulator_move_priority_elements(triangle_maker, instructor, \
		priority_amount - 1));
}

static t_push_swap_error_code	emulator_push_priority_from_front(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instructor *instructor, unsigned int priority_amount)
{
	if (emulator_get_priority_by_index(triangle_maker, 1) == \
		triangle_maker->highest_priority)
		return (triangle_maker_formula_front2(triangle_maker, instructor));
	if (emulated_instructor_add(triangle_maker, instructor, PB))
		return (FAILURE);
	return (emulator_move_priority_elements(triangle_maker, instructor, \
		priority_amount - 1));
}

static t_push_swap_error_code	emulator_ra_or_sa_till_priority_found(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instructor *instructor, unsigned int priority_amount)
{
	if ((emulator_get_priority_by_index(triangle_maker, 1) == \
		triangle_maker->highest_priority) && \
		emulator_is_priority_decrease_after_sa(triangle_maker, \
			emulator_get_priority_by_index(triangle_maker, 0)))
	{
		if (emulated_instructor_add(triangle_maker, instructor, SA))
			return (FAILURE);
		return (emulator_move_priority_elements(triangle_maker, instructor, \
			priority_amount));
	}
	if (emulated_instructor_add(triangle_maker, instructor, RA))
		return (FAILURE);
	return (emulator_move_priority_elements(triangle_maker, instructor, \
		priority_amount));
}

static t_push_swap_error_code	emulator_rra_till_priority_found(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instructor *instructor, unsigned int priority_amount)
{
	if (emulated_instructor_add(triangle_maker, instructor, RRA))
		return (FAILURE);
	return (emulator_move_priority_elements(triangle_maker, instructor, \
		priority_amount));
}

t_push_swap_error_code	emulator_move_priority_elements(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
unsigned int priority_amount)
{
	if (priority_amount == 0)
	{
		return (SUCCESS);
	}
	if (emulator_get_priority_by_index(triangle_maker, -1) == \
		triangle_maker->highest_priority)
		return (emulator_push_priority_from_rear(triangle_maker, \
			instructor, priority_amount));
	if (emulator_get_priority_by_index(triangle_maker, 0) == \
		triangle_maker->highest_priority)
		return (emulator_push_priority_from_front(triangle_maker, \
			instructor, priority_amount));
	if (emulator_search_priority_location(triangle_maker, \
		triangle_maker->highest_priority) \
		== PRIORITY_AT_FRONT)
		return (emulator_ra_or_sa_till_priority_found(triangle_maker, \
			instructor, priority_amount));
	return (emulator_rra_till_priority_found(triangle_maker, instructor, \
		priority_amount));
}
