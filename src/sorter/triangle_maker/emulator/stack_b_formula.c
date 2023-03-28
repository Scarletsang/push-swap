/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:33 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 07:41:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker/emulator.h"

t_push_swap_error_code	emulator_formula_front2(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor)
{
	triangle_maker->last_formula_executed = &emulator_formula_front2;
	if (stack_get_element_by_index(&triangle_maker->emulation.stack_a, 0) < \
		stack_get_element_by_index(&triangle_maker->emulation.stack_a, 1))
	{
		if (instructor->last_instruction->instruction == SB)
		{
			emulated_instructor_edit_last(triangle_maker, instructor, SS);
			return (emulated_instructor_add_formula(triangle_maker, instructor, \
				(t_push_swap_instruction[3]){2, PB, PB}));
		}
		return (emulated_instructor_add_formula(triangle_maker, instructor, \
			(t_push_swap_instruction[4]){3, PB, PB, SB}));
	}
	return (emulated_instructor_add_formula(triangle_maker, instructor, \
		(t_push_swap_instruction[3]){2, PB, PB}));
}

t_push_swap_error_code	emulator_formula_front1rear1(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor)
{
	triangle_maker->last_formula_executed = &emulator_formula_front1rear1;
	if (stack_get_element_by_index(&triangle_maker->emulation.stack_a, 0) > \
		stack_get_element_by_index(&triangle_maker->emulation.stack_a, -1))
	{
		return (emulated_instructor_add_formula(triangle_maker, instructor, \
			(t_push_swap_instruction[4]){3, PB, RRA, PB}));
	}
	return (emulated_instructor_add_formula(triangle_maker, instructor, \
		(t_push_swap_instruction[4]){3, RRA, PB, PB}));
}

t_push_swap_error_code	emulator_formula_rear1(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor)
{
	if ((triangle_maker->last_formula_executed == \
		&emulator_formula_rear1) \
		&& (stack_get_element_by_index(&triangle_maker->emulation.stack_a, -1) \
		> stack_get_element_by_index(&triangle_maker->emulation.stack_b, 0)))
	{
		triangle_maker->last_formula_executed = NULL;
		emulated_instructor_edit_last(triangle_maker, instructor, RRA);
		return (emulated_instructor_add_formula(triangle_maker, instructor, \
			(t_push_swap_instruction[3]){2, PB, PB}));
	}
	triangle_maker->last_formula_executed = &emulator_formula_rear1;
	return (emulated_instructor_add_formula(triangle_maker, instructor, \
		(t_push_swap_instruction[3]){2, RRA, PB}));
}

t_push_swap_error_code	emulator_formula_last2(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor)
{
	if (triangle_maker->emulated_stack_a_rear_size == 0)
		return (emulator_formula_front2(triangle_maker, instructor));
	if (triangle_maker->emulated_stack_a_rear_size == 1)
		return (emulator_formula_front1rear1(triangle_maker, instructor));
	if (emulator_formula_rear1(triangle_maker, instructor))
		return (FAILURE);
	return (emulator_formula_rear1(triangle_maker, instructor));
}

t_push_swap_error_code	emulator_formula_last1(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor)
{
	if (triangle_maker->emulated_stack_a_rear_size == 0)
		return (emulated_instructor_add(triangle_maker, instructor, PB));
	return (emulator_formula_rear1(triangle_maker, instructor));
}
