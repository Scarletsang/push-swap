/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_executor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:40 by htsang            #+#    #+#             */
/*   Updated: 2023/03/21 23:15:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/instructor.h"

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

t_push_swap_instruction	get_inverse_instruction(\
t_push_swap_instruction instruction)
{
	if (instruction < 0)
		return (instruction);
	return (PB - instruction);
}

void	edit_last_instruction(t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction)
{
	if (instructor->last_instruction == instructor->last_executed_instruction)
	{
		execute_instruction(instructor->two_stacks, \
			get_inverse_instruction(instructor->last_instruction->instruction));
		instructor->last_instruction->instruction = instruction;
		execute_instruction(instructor->two_stacks, instruction);
		return ;
	}
	instructor->last_instruction->instruction = instruction;
}

void	execute_unexecuted_instructions(t_push_swap_instructor *instructor)
{
	t_push_swap_instruction_list	*instruction_node;

	instruction_node = instructor->last_executed_instruction->next;
	while (instruction_node)
	{
		execute_instruction(instructor->two_stacks, \
			instruction_node->instruction);
		instructor->last_executed_instruction = instruction_node;
		instruction_node = instructor->last_executed_instruction->next;
	}
}
