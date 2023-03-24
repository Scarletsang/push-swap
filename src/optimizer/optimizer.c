/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:48:12 by htsang            #+#    #+#             */
/*   Updated: 2023/03/25 00:35:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/optimizer.h"

t_push_swap_optimize_possible	init_striker(\
t_push_swap_instruction_striker *striker, \
t_push_swap_instruction_list *instruction_list)
{
	if (!instruction_list->next)
		return (NOTHING_TO_OPTIMIZE);
	striker->hits = instruction_list->next;
	striker->target = striker->hits->instruction;
	striker->inverse_target = get_inverse_instruction(striker->target);
	striker->amount_of_consecutive_hits = 0;
	striker->amount_of_consecutive_inverse_hits = 0;
	return (OPTIMIZATION_COMPLETE);
}

t_push_swap_optimize_possible	strike_down_instructions(\
t_push_swap_instruction_list *instruction_list)
{
	t_push_swap_instruction_striker	striker;

	if (init_striker(&striker, instruction_list))
		return (NOTHING_TO_OPTIMIZE);
	while (striker.hits && (striker.hits->instruction == striker.target))
	{
		striker.amount_of_consecutive_hits++;
		striker.hits = striker.hits->next;
	}
	while (striker.hits && (striker.amount_of_consecutive_inverse_hits < \
		striker.amount_of_consecutive_hits) \
		&& (striker.hits->instruction == striker.inverse_target))
	{
		striker.amount_of_consecutive_inverse_hits++;
		striker.hits = striker.hits->next;
	}
	striker.hits = instruction_list;
	while ()
	{
		/* code */
	}
	return (strike(striker, instruction_list));
}

t_push_swap_optimize_possible	combine(\
t_push_swap_instruction target_instruction, t_push_swap_instructor *instructor)
{
	
}
