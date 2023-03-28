/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:41:13 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:30:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/instructor.h"

t_push_swap_instruction	instruction_get_inverse(\
t_push_swap_instruction instruction)
{
	if (instruction < 0)
		return (instruction);
	return (PB - instruction);
}

void	instruction_list_free_all(t_push_swap_instruction_list *instruction)
{
	t_push_swap_instruction_list	*tmp;

	while (instruction)
	{
		tmp = instruction;
		instruction = instruction->next;
		free(tmp);
	}
}
