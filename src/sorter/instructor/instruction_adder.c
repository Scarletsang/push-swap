/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_adder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:40 by htsang            #+#    #+#             */
/*   Updated: 2023/03/23 13:24:18 by htsang           ###   ########.fr       */
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
t_push_swap_instruction *instruction_arr)
{
	unsigned int	i;

	i = 0;
	while (i < (unsigned int) instruction_arr[0])
	{
		if (add_instruction(instructor, instruction_arr[i + 1]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
