/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 17:41:13 by htsang            #+#    #+#             */
/*   Updated: 2023/03/26 17:41:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/instructor.h"

t_push_swap_instruction	get_inverse_instruction(\
t_push_swap_instruction instruction)
{
	if (instruction < 0)
		return (instruction);
	return (PB - instruction);
}

void	free_instruction_list(t_push_swap_instruction_list *instruction)
{
	t_push_swap_instruction_list	*tmp;

	while (instruction)
	{
		tmp = instruction;
		instruction = instruction->next;
		free(tmp);
	}
}
