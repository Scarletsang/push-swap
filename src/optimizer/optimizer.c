/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:48:12 by htsang            #+#    #+#             */
/*   Updated: 2023/03/25 17:59:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/optimizer.h"

static t_push_swap_optimize_possible	init_striker(\
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

static t_push_swap_optimize_possible	striker_look_for_targets(\
t_push_swap_instruction_striker *striker)
{
	while (striker->hits && (striker->hits->instruction == striker->target))
	{
		striker->amount_of_consecutive_hits++;
		striker->hits = striker->hits->next;
	}
	if (striker->target == striker->inverse_target)
	{
		striker->amount_of_consecutive_inverse_hits = \
			striker->amount_of_consecutive_hits;
		return (striker->amount_of_consecutive_hits == 1);
	}
	while (striker->hits && (striker->amount_of_consecutive_inverse_hits \
		< striker->amount_of_consecutive_hits) \
		&& (striker->hits->instruction == striker->inverse_target))
	{
		striker->amount_of_consecutive_inverse_hits++;
		striker->hits = striker->hits->next;
	}
	return (striker->amount_of_consecutive_inverse_hits == 0);
}

static t_push_swap_optimize_possible	strike_down_instructions(\
t_push_swap_instruction_striker *striker, \
t_push_swap_instruction_list *instruction_list)
{
	t_push_swap_instruction_list	*tmp;
	unsigned int					amount_of_hits;

	if (init_striker(striker, instruction_list) || \
		striker_look_for_targets(striker))
		return (NOTHING_TO_OPTIMIZE);
	striker->hits = instruction_list;
	while ((striker->amount_of_consecutive_hits - 1) > \
		striker->amount_of_consecutive_inverse_hits)
	{
		striker->amount_of_consecutive_hits--;
		striker->hits = striker->hits->next;
	}
	amount_of_hits = striker->amount_of_consecutive_hits * 2;
	while (amount_of_hits > 0)
	{
		tmp = striker->hits->next;
		striker->hits->next = striker->hits->next->next;
		free(tmp);
		amount_of_hits--;
	}
	return (OPTIMIZATION_COMPLETE);
}

void	optmize_instructions(t_push_swap_instructor *instructor)
{
	t_push_swap_instruction_list	*optimizer;
	t_push_swap_instruction_striker	striker;

	optimizer = instructor->cost;
	while (optimizer)
	{
		if (strike_down_instructions(&striker, optimizer) \
			== OPTIMIZATION_COMPLETE)
		{
			increase_cost_by(instructor, -2 * \
				striker.amount_of_consecutive_hits);
		}
		else
		{
			optimizer = optimizer->next;
		}
	}
}

// t_push_swap_optimize_possible	combine(\
// t_push_swap_instruction target_instruction, t_push_swap_instructor *instructor)
// {
	
// }
