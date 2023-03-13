/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:29:44 by htsang            #+#    #+#             */
/*   Updated: 2023/03/13 23:13:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

void	concat_sorter(t_push_swap_sorter *to, t_push_swap_sorter *from)
{
	increase_cost_by(to, get_cost(from));
	to->last_instruction->next = from->cost->next;
	to->last_instruction = from->last_instruction;
}

void	free_sorter_internals(t_push_swap_sorter *sorter)
{
	t_push_swap_instruction_list	*tmp;

	while (sorter->cost)
	{
		tmp = sorter->cost;
		sorter->cost = sorter->cost->next;
		free(tmp);
	}
	free_two_stacks(&sorter->emulation);
}

void	increase_cost_by(t_push_swap_sorter *sorter, int cost)
{
	sorter->cost->instruction += cost;
}

int	get_cost(t_push_swap_sorter *sorter)
{
	return (sorter->cost->instruction);
}

t_push_swap_error_code	init_sorter(t_push_swap_sorter *sorter)
{
	sorter->cost = malloc(sizeof(t_push_swap_instruction_list));
	if (!sorter->cost)
		return (FAILURE);
	if (init_empty_stack(&sorter->emulation.stack_a, EMULATION_STACK_SIZE) || \
		init_empty_stack(&sorter->emulation.stack_b, EMULATION_STACK_SIZE))
		return (FAILURE);
	sorter->cost->instruction = 0;
	sorter->cost->next = NULL;
	sorter->last_instruction = sorter->cost;
	sorter->last_executed_instruction = sorter->cost;
	return (SUCCESS);
}
