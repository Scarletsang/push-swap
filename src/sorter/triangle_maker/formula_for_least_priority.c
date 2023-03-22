/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula_for_least_priority.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:31:09 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 14:31:36 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

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


t_push_swap_error_code	last2_of_last_triangle(\
t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	if ((triangle_maker->triangle_size % 2) == 0)
	{
		if (get_element_by_index(&triangle_maker->emulation.stack_a, 0) < \
			get_element_by_index(&triangle_maker->emulation.stack_a, 1))
			return (emulate_instruction(instructor, triangle_maker, SA));
		return (SUCCESS);
	}
	if (get_element_by_index(&triangle_maker->emulation.stack_b, 0) < \
		get_element_by_index(&triangle_maker->emulation.stack_a, 0))
		edit_last_emulated_instruction(instructor, triangle_maker, SA);
	else
		edit_last_emulated_instruction(instructor, triangle_maker, PA);
	return (SUCCESS);
}
