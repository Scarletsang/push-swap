/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 04:33:48 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:31:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/instructor.h"

void	instructor_concat(t_push_swap_instructor *to, \
t_push_swap_instructor *from)
{
	if (from->last_instruction != from->cost)
	{
		instructor_increase_cost_by(to, instructor_get_cost(from));
		to->last_instruction->next = from->cost->next;
		to->last_instruction = from->last_instruction;
		from->cost->instruction = 0;
		from->cost->next = NULL;
		from->last_instruction = from->cost;
		from->last_executed_instruction = from->cost;
	}
}

void	instructor_increase_cost_by(\
t_push_swap_instructor *instructor, int cost)
{
	instructor->cost->instruction += cost;
}

int	instructor_get_cost(t_push_swap_instructor *instructor)
{
	return (instructor->cost->instruction);
}

t_push_swap_error_code	instructor_init(t_push_swap_instructor *instructor, \
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
