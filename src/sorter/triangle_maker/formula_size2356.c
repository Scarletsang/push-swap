/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula_size2356.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 14:31:09 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:29:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

t_push_swap_error_code	size2(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	if (stack_get_element_by_index(&triangle_maker->emulation.stack_a, 0) > \
		stack_get_element_by_index(&triangle_maker->emulation.stack_a, 1))
		return (instructor_add(instructor, SA));
	return (SUCCESS);
}

t_push_swap_error_code	size3(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	unsigned int	index_of_2;

	index_of_2 = 0;
	while ((index_of_2 < 4) && (stack_get_element_by_index(\
		&triangle_maker->emulation.stack_a, index_of_2) != 2))
		index_of_2++;
	if (index_of_2 == 0)
	{
		if (instructor_add(instructor, RA))
			return (FAILURE);
	}
	else if (index_of_2 == 1)
	{
		if (instructor_add(instructor, RRA))
			return (FAILURE);
	}
	return (size2(instructor, triangle_maker));
}

t_push_swap_error_code	size5_or_6(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	unsigned int	piroity_size;

	piroity_size = triangle_maker->triangle_size - 4;
	triangle_maker->highest_priority = LOWEST_PRIORITY;
	move_priority_elements(instructor, triangle_maker, piroity_size);
	if (size4(instructor, triangle_maker))
		return (FAILURE);
	if (piroity_size == 2)
	{
		if (stack_get_element_by_index(&triangle_maker->emulation.stack_b, 1) > \
			stack_get_element_by_index(&triangle_maker->emulation.stack_b, 0))
		{
			if (instructor->last_instruction->instruction == SA)
				instructor_edit_last(instructor, SS);
			else if (instructor_add(instructor, SB))
				return (FAILURE);
		}
		return (instructor_add_multiple(instructor, \
			(t_push_swap_instruction[3]){2, PA, PA}));
	}
	return (instructor_add(instructor, PA));
}
