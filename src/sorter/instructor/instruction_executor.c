/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_executor.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:53:40 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:30:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/instructor.h"

static void	instructor_execute_rotate(t_push_swap_2stacks *two_stacks, \
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

void	instructor_execute(t_push_swap_2stacks *two_stacks, \
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
		instructor_execute_rotate(two_stacks, instruction);
}

void	instructor_edit_last(t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction)
{
	if (instructor->last_instruction == instructor->last_executed_instruction)
	{
		instructor_execute(instructor->two_stacks, \
			instruction_get_inverse(instructor->last_instruction->instruction));
		instructor->last_instruction->instruction = instruction;
		instructor_execute(instructor->two_stacks, instruction);
		return ;
	}
	instructor->last_instruction->instruction = instruction;
}

void	instructor_execute_unexecuted(t_push_swap_instructor *instructor)
{
	t_push_swap_instruction_list	*instruction_node;

	instruction_node = instructor->last_executed_instruction->next;
	while (instruction_node)
	{
		instructor_execute(instructor->two_stacks, \
			instruction_node->instruction);
		instructor->last_executed_instruction = instruction_node;
		instruction_node = instructor->last_executed_instruction->next;
	}
}
