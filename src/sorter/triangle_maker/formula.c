/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:33 by htsang            #+#    #+#             */
/*   Updated: 2023/03/21 22:02:22 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

t_push_swap_error_code	front2(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	triangle_maker->last_formula_executed = &front2;
	if (get_element_by_index(&triangle_maker->emulation.stack_a, 0) < \
		get_element_by_index(&triangle_maker->emulation.stack_a, 1))
	{
		if (instructor->last_instruction->instruction == SB)
		{
			edit_last_emulated_instruction(instructor, triangle_maker, SS);
			return (emulate_formula_instructions(instructor, triangle_maker, \
				(t_push_swap_instruction[3]){2, PB, PB}));
		}
		return (emulate_formula_instructions(instructor, triangle_maker, \
			(t_push_swap_instruction[4]){3, PB, PB, SB}));
	}
	return (emulate_formula_instructions(instructor, triangle_maker, \
		(t_push_swap_instruction[3]){2, PB, PB}));
}

t_push_swap_error_code	front1rear1(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	triangle_maker->last_formula_executed = &front1rear1;
	if (get_element_by_index(&triangle_maker->emulation.stack_a, 0) > \
		get_element_by_index(&triangle_maker->emulation.stack_a, -1))
	{
		return (emulate_formula_instructions(instructor, triangle_maker, \
			(t_push_swap_instruction[4]){3, PB, RRA, PB}));
	}
	return (emulate_formula_instructions(instructor, triangle_maker, \
		(t_push_swap_instruction[4]){3, RRA, PB, PB}));
}

t_push_swap_error_code	rear1(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	if ((triangle_maker->last_formula_executed == &rear1) && \
		(get_element_by_index(&triangle_maker->emulation.stack_a, -1) > \
		get_element_by_index(&triangle_maker->emulation.stack_b, 0)))
	{
		triangle_maker->last_formula_executed = NULL;
		edit_last_emulated_instruction(instructor, triangle_maker, RRA);
		return (emulate_formula_instructions(instructor, triangle_maker, \
			(t_push_swap_instruction[3]){2, PB, PB}));
	}
	triangle_maker->last_formula_executed = &rear1;
	return (emulate_formula_instructions(instructor, triangle_maker, \
		(t_push_swap_instruction[3]){2, RRA, PB}));
}

t_push_swap_error_code	last2(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	if (triangle_maker->emulated_stack_a_rear_size == 0)
		return (front2(instructor, triangle_maker));
	if (triangle_maker->emulated_stack_a_rear_size == 1)
		return (front1rear1(instructor, triangle_maker));
	if (rear1(instructor, triangle_maker))
		return (FAILURE);
	return (rear1(instructor, triangle_maker));
}

t_push_swap_error_code	last1(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	if (triangle_maker->emulated_stack_a_rear_size == 0)
		return (emulate_instruction(instructor, triangle_maker, PB));
	return (rear1(instructor, triangle_maker));
}
