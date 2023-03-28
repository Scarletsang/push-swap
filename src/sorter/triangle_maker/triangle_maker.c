/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:09:35 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 07:39:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"
#include "PUSH_SWAP/sorter/triangle_maker/emulator.h"

t_push_swap_error_code	triangle_maker_create_triangle_on_stack_a(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instructor *instructor)
{
	if (triangle_maker->triangle_size == TRIANGLE_SIZE_2)
		return (triangle_maker_formula_size2(triangle_maker, instructor));
	if (triangle_maker->triangle_size == TRIANGLE_SIZE_3)
		return (triangle_maker_formula_size3(triangle_maker, instructor));
	if (triangle_maker->triangle_size == TRIANGLE_SIZE_4)
		return (triangle_maker_formula_size4(triangle_maker, instructor));
	return (triangle_maker_formula_size5_or_6(triangle_maker, instructor));
}

t_push_swap_error_code	triangle_maker_create_triangle_on_stack_b(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instructor *instructor)
{
	while (triangle_maker->highest_priority > 0)
	{
		if (emulator_move_priority_elements(triangle_maker, instructor, 2))
			return (FAILURE);
		if (stack_get_element_by_index(&triangle_maker->emulation.stack_b, 0) > \
			stack_get_element_by_index(&triangle_maker->emulation.stack_b, 1))
		{
			if (instructor_add(instructor, SB))
				return (FAILURE);
		}
		triangle_maker->highest_priority--;
	}
	if ((triangle_maker->triangle_size % 2) == 0)
	{
		return (emulator_formula_last2(triangle_maker, instructor));
	}
	return (emulator_formula_last1(triangle_maker, instructor));
}

void	triangle_maker_update(t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_triangle_size triangle_size, \
t_push_swap_triangle_shape triangle_shape)
{
	*(t_push_swap_triangle_size *) &triangle_maker->triangle_size = \
		triangle_size;
	*(t_push_swap_triangle_shape *) &triangle_maker->triangle_shape = \
		triangle_shape;
	triangle_maker->emulation.stack_a.size = 0;
	triangle_maker->emulation.stack_a.front = 0;
	triangle_maker->emulation.stack_a.rear = 0;
	triangle_maker->emulation.stack_b.size = 0;
	triangle_maker->emulation.stack_b.front = 0;
	triangle_maker->emulation.stack_b.rear = 0;
	triangle_maker->emulated_stack_a_rear_size = 0;
	triangle_maker->emulated_stack_a_front_size = triangle_size;
	triangle_maker->priority_location = UNKNOWN_PRIORITY_LOCATION;
	triangle_maker->highest_priority = \
		emulator_get_priority_of_value(triangle_maker, \
			triangle_size - 1);
	triangle_maker->last_formula_executed = NULL;
}

t_push_swap_error_code	triangle_maker_init(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	if (stack_init_empty(&triangle_maker->emulation.stack_a, \
		EMULATION_STACK_SIZE) || \
		stack_init_empty(&triangle_maker->emulation.stack_b, \
		EMULATION_STACK_SIZE) || \
		instructor_init(instructor, &triangle_maker->emulation))
		return (FAILURE);
	triangle_maker->priority_location = UNKNOWN_PRIORITY_LOCATION;
	instructor->automatic_execute = 1;
	return (SUCCESS);
}
