/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:56:33 by htsang            #+#    #+#             */
/*   Updated: 2023/03/20 22:11:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

t_push_swap_error_code	front2(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker)
{
	if (get_element_by_index(&triangle_maker->emulation.stack_a, 0) < \
		get_element_by_index(&triangle_maker->emulation.stack_a, 1))
	{
		if (sorter->last_instruction->instruction == SB)
		{
			edit_last_instruction(sorter, SS);
			return (add_multiple_instructions(sorter, \
				(t_push_swap_instruction[2]){PB, PB}, 2));
		}
		return (add_multiple_instructions(sorter, \
			(t_push_swap_instruction[3]){PB, PB, SB}, 3));
	}
	return (add_multiple_instructions(sorter, \
		(t_push_swap_instruction[2]){PB, PB}, 2));
}

t_push_swap_error_code	front1rear1(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker)
{
	triangle_maker->emulated_stack_a_rear_size--;
	if (get_element_by_index(&triangle_maker->emulation.stack_a, 0) > \
		get_element_by_index(&triangle_maker->emulation.stack_a, -1))
	{
		return (add_multiple_instructions(sorter, \
			(t_push_swap_instruction[3]){PB, RRA, PB}, 3));
	}
	return (add_multiple_instructions(sorter, \
		(t_push_swap_instruction[3]){RRA, PB, PB}, 3));
}

t_push_swap_error_code	rear1(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker)
{
	triangle_maker->emulated_stack_a_rear_size--;
	if ((triangle_maker->last_formula_executed == &rear1) && \
		(get_element_by_index(&triangle_maker->emulation.stack_a, -1) > \
		get_element_by_index(&triangle_maker->emulation.stack_b, 0)))
	{
		edit_last_instruction(sorter, RRA);
		return (add_multiple_instructions(sorter, \
			(t_push_swap_instruction[2]){PB, PB}, 2));
	}
	return (add_multiple_instructions(sorter, \
		(t_push_swap_instruction[2]){RRA, PB}, 2));
}

t_push_swap_error_code	rear2(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker)
{
	triangle_maker->emulated_stack_a_rear_size--;
	if (add_instruction(sorter, RRA))
		return (FAILURE);
	return (front1rear1(sorter, triangle_maker));
}
