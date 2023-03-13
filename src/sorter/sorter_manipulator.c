/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_manipulator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:40 by htsang            #+#    #+#             */
/*   Updated: 2023/03/13 20:29:40 by htsang           ###   ########.fr       */
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

static void	execute_rotate_instruction(t_push_swap_2stacks *two_stacks, \
t_push_swap_instruction instruction)
{
	if (instruction == RA)
		rotate(&two_stacks->stack_a);
	else if (instruction == RB)
		rotate(&two_stacks->stack_b);
	else if (instruction == RR)
	{
		rotate(&two_stacks->stack_a);
		rotate(&two_stacks->stack_b);
	}
	else if (instruction == RRA)
		reverse_rotate(&two_stacks->stack_a);
	else if (instruction == RRB)
		reverse_rotate(&two_stacks->stack_b);
	else if (instruction == RRR)
	{
		reverse_rotate(&two_stacks->stack_a);
		reverse_rotate(&two_stacks->stack_b);
	}
}

static void	execute_instruction(t_push_swap_2stacks *two_stacks, \
t_push_swap_instruction instruction)
{
	if (instruction == SA)
		swap(&two_stacks->stack_a);
	else if (instruction == SB)
		swap(&two_stacks->stack_b);
	else if (instruction == SS)
	{
		swap(&two_stacks->stack_a);
		swap(&two_stacks->stack_b);
	}
	else if (instruction == PA)
		push(&two_stacks->stack_a, &two_stacks->stack_b);
	else if (instruction == PB)
		push(&two_stacks->stack_b, &two_stacks->stack_a);
	else
		execute_rotate_instruction(two_stacks, instruction);
}

void	execute_instructions(t_push_swap_sorter *sorter, \
t_push_swap_2stacks *two_stacks, unsigned int amount)
{
	t_push_swap_instruction_list	*instruction_node;

	instruction_node = sorter->last_executed_instruction->next;
	while (instruction_node && (amount > 0))
	{
		execute_instruction(two_stacks, instruction_node->instruction);
		sorter->last_executed_instruction = instruction_node;
		instruction_node = sorter->last_executed_instruction->next;
		amount--;
	}
}
