/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:09:35 by htsang            #+#    #+#             */
/*   Updated: 2023/03/23 13:04:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

t_push_swap_error_code	create_triangle_on_stack_a(\
t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	if (triangle_maker->triangle_size == TRIANGLE_SIZE_2)
		return (size2(instructor, triangle_maker));
	if (triangle_maker->triangle_size == TRIANGLE_SIZE_3)
		return (size3(instructor, triangle_maker));
	if (triangle_maker->triangle_size == TRIANGLE_SIZE_4)
		return (size4(instructor, triangle_maker));
	return (size5_or_6(instructor, triangle_maker));
}

t_push_swap_error_code	create_triangle_on_stack_b(\
t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	while (triangle_maker->highest_priority > 0)
	{
		if (move_priority_elements(instructor, triangle_maker, 2, \
			UNKNOWN_PRIORITY_LOCATION))
			return (FAILURE);
		triangle_maker->highest_priority--;
	}
	if ((triangle_maker->triangle_size % 2) == 0)
	{
		return (last2(instructor, triangle_maker));
	}
	return (last1(instructor, triangle_maker));
}

void	prepare_emulation(t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_triangle_size triangle_size, \
t_push_swap_triangle_shape triangle_shape)
{
	triangle_maker->triangle_size = triangle_size;
	triangle_maker->triangle_shape = triangle_shape;
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
		get_emulation_priority_by_value(triangle_size - 1, triangle_maker);
	triangle_maker->last_formula_executed = NULL;
}

t_push_swap_error_code	init_triangle_maker(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	if (init_empty_stack(&triangle_maker->emulation.stack_a, \
		EMULATION_STACK_SIZE) || \
		init_empty_stack(&triangle_maker->emulation.stack_b, \
		EMULATION_STACK_SIZE) || \
		init_instructor(instructor, &triangle_maker->emulation))
		return (FAILURE);
	triangle_maker->priority_location = UNKNOWN_PRIORITY_LOCATION;
	instructor->automatic_execute = 1;
	return (SUCCESS);
}
