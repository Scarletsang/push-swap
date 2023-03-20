/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:40 by htsang            #+#    #+#             */
/*   Updated: 2023/03/20 20:58:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

t_push_swap_error_code	add_instruction(t_push_swap_sorter *sorter, \
t_push_swap_instruction instruction)
{
	t_push_swap_instruction_list	*new_instruction;

	new_instruction = malloc(sizeof(t_push_swap_instruction_list));
	if (!new_instruction)
		return (FAILURE);
	increase_cost_by(sorter, 1);
	new_instruction->instruction = instruction;
	new_instruction->next = NULL;
	sorter->last_instruction->next = new_instruction;
	sorter->last_instruction = new_instruction;
	if (sorter->automatic_execute)
		execute_instruction_from_sorter(sorter, 1);
	return (SUCCESS);
}

t_push_swap_error_code	add_multiple_instructions(t_push_swap_sorter *sorter, \
t_push_swap_instruction *instruction_arr, unsigned int amount)
{
	while (amount > 0)
	{
		if (add_instruction(sorter, *instruction_arr))
			return (FAILURE);
		instruction_arr++;
		amount--;
	}
	return (SUCCESS);
}

t_push_swap_error_code	add_instructions_n_times(t_push_swap_sorter *sorter, \
t_push_swap_instruction instruction, unsigned int amount)
{
	while (amount > 0)
	{
		if (add_instruction(sorter, instruction))
			return (FAILURE);
		amount--;
	}
	return (SUCCESS);
}
