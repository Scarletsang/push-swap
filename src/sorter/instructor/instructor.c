/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 04:33:48 by htsang            #+#    #+#             */
/*   Updated: 2023/03/24 01:43:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/instructor.h"

void	concat_instructor(t_push_swap_instructor *to, \
t_push_swap_instructor *from)
{
	increase_cost_by(to, get_cost(from));
	to->last_instruction->next = from->cost->next;
	to->last_instruction = from->last_instruction;
	from->cost->instruction = 0;
	from->cost->next = NULL;
	from->last_instruction = from->cost;
	from->last_executed_instruction = from->cost;
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

void	increase_cost_by(t_push_swap_instructor *instructor, int cost)
{
	instructor->cost->instruction += cost;
}

int	get_cost(t_push_swap_instructor *instructor)
{
	return (instructor->cost->instruction);
}

t_push_swap_error_code	init_instructor(t_push_swap_instructor *instructor, \
t_push_swap_2stacks *two_stacks)
{
	instructor->cost = malloc(sizeof(t_push_swap_instruction_list));
	if (!instructor->cost)
		return (FAILURE);
	instructor->cost->instruction = 0;
	instructor->cost->next = NULL;
	instructor->last_instruction = instructor->cost;
	instructor->last_executed_instruction = instructor->cost;
	instructor->two_stacks = two_stacks;
	instructor->automatic_execute = 0;
	return (SUCCESS);
}
