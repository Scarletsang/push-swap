/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_executor.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:40 by htsang            #+#    #+#             */
/*   Updated: 2023/03/20 20:59:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

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

void	execute_instruction(t_push_swap_2stacks *two_stacks, \
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

static void	undo_instruction(t_push_swap_2stacks *two_stacks, \
t_push_swap_instruction instruction)
{
	if (instruction < 0)
		execute_instruction(two_stacks, instruction);
	else
		execute_instruction(two_stacks, PB - instruction);
}

void	edit_last_instruction(t_push_swap_sorter *sorter, \
t_push_swap_instruction instruction)
{
	if (sorter->last_instruction == sorter->last_executed_instruction)
	{
		undo_instruction(sorter->two_stacks, \
			sorter->last_instruction->instruction);
		sorter->last_instruction->instruction = instruction;
		execute_instruction(sorter->two_stacks, instruction);
		return ;
	}
	sorter->last_instruction->instruction = instruction;
}

void	execute_instruction_from_sorter(t_push_swap_sorter *sorter, \
unsigned int amount)
{
	t_push_swap_instruction_list	*instruction_node;

	instruction_node = sorter->last_executed_instruction->next;
	while (instruction_node && (amount > 0))
	{
		execute_instruction(&sorter->two_stacks, \
			instruction_node->instruction);
		sorter->last_executed_instruction = instruction_node;
		instruction_node = sorter->last_executed_instruction->next;
		amount--;
	}
}
