/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_adder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:40 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 04:34:12 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/instructor.h"

t_push_swap_error_code	add_instruction(t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction)
{
	t_push_swap_instruction_list	*new_instruction;

	new_instruction = malloc(sizeof(t_push_swap_instruction_list));
	if (!new_instruction)
		return (FAILURE);
	increase_cost_by(instructor, 1);
	new_instruction->instruction = instruction;
	new_instruction->next = NULL;
	instructor->last_instruction->next = new_instruction;
	instructor->last_instruction = new_instruction;
	if (instructor->automatic_execute)
		execute_unexecuted_instructions(instructor);
	return (SUCCESS);
}

t_push_swap_error_code	add_multiple_instructions(\
t_push_swap_instructor *instructor, \
t_push_swap_instruction *instruction_arr, unsigned int amount)
{
	while (amount > 0)
	{
		if (add_instruction(instructor, *instruction_arr))
			return (FAILURE);
		instruction_arr++;
		amount--;
	}
	return (SUCCESS);
}

t_push_swap_error_code	add_instructions_n_times(\
t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction, unsigned int amount)
{
	while (amount > 0)
	{
		if (add_instruction(instructor, instruction))
			return (FAILURE);
		amount--;
	}
	return (SUCCESS);
}
