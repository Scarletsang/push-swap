/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_adder.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:40 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:30:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/instructor.h"

t_push_swap_error_code	instructor_add(t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction)
{
	t_push_swap_instruction_list	*new_instruction;

	new_instruction = malloc(sizeof(t_push_swap_instruction_list));
	if (!new_instruction)
		return (FAILURE);
	instructor_increase_cost_by(instructor, 1);
	new_instruction->instruction = instruction;
	new_instruction->next = NULL;
	instructor->last_instruction->next = new_instruction;
	instructor->last_instruction = new_instruction;
	if (instructor->automatic_execute)
		instructor_execute_unexecuted(instructor);
	return (SUCCESS);
}

t_push_swap_error_code	instructor_add_multiple(\
t_push_swap_instructor *instructor, \
t_push_swap_instruction *instruction_arr)
{
	unsigned int	i;

	i = 0;
	while (i < (unsigned int) instruction_arr[0])
	{
		if (instructor_add(instructor, instruction_arr[i + 1]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

t_push_swap_error_code	instructor_add_n_times(\
t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (instructor_add(instructor, instruction))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
