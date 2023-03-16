/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:34:18 by htsang            #+#    #+#             */
/*   Updated: 2023/03/16 21:11:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

t_push_swap_error_code	add_and_execute_instruction(\
t_push_swap_sorter *sorter, t_push_swap_instruction instruction)
{
	if (add_instructions(sorter, instruction))
		return (FAILURE);
	execute_instruction(sorter, instruction);
	return (SUCCESS);
}

t_push_swap_error_code	make_ascending_triangle(t_push_swap_sorter *sorter, \
t_push_swap_triangle_size triangle_size)
{
	t_push_swap_emulation_group			priority_group;

	priority_group = get_emulation_group((triangle_size - 1), \
		triangle_size, ASCENDING_TRIANGLE);
	while (sorter->emulation_range_from <= RANGE_FROM_MINUS_1)
	{
		if (get_emulation_group(get_element_by_index(\
				&sorter->emulation.stack_a, RANGE_FROM_MINUS_1), \
					triangle_size, ASCENDING_TRIANGLE) == priority_group)
			if (add_and_execute_instruction(sorter, PB))
				return (FAILURE);
			break ;
		if (add_and_execute_instruction(sorter, RRA))
			return (FAILURE);
		sorter->emulation_range_from++;
	}
	
}
