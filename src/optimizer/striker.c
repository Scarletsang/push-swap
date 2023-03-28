/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   striker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:48:12 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:30:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/optimizer.h"

static t_push_swap_optimize_possible	optimizer_striker_look_for_targets(\
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
			striker->amount_of_consecutive_hits / 2;
		striker->amount_of_consecutive_hits = \
			(striker->amount_of_consecutive_hits / 2) + \
			(striker->amount_of_consecutive_hits % 2);
		return (striker->amount_of_consecutive_inverse_hits == 0);
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

static t_push_swap_optimize_possible	optimizer_striker_init(\
t_push_swap_instruction_striker *striker, \
t_push_swap_instruction_list *instruction_list)
{
	if (!instruction_list->next)
		return (NOTHING_TO_OPTIMIZE);
	striker->hits = instruction_list->next;
	striker->target = striker->hits->instruction;
	striker->inverse_target = instruction_get_inverse(striker->target);
	striker->amount_of_consecutive_hits = 0;
	striker->amount_of_consecutive_inverse_hits = 0;
	return (OPTIMIZE_POSSIBLE);
}

t_push_swap_optimize_possible	optimizer_strike_down_instructions(\
t_push_swap_instruction_striker *striker, \
t_push_swap_instruction_list *instruction_list)
{
	t_push_swap_instruction_list	*tmp;
	unsigned int					amount_of_hits;

	if (optimizer_striker_init(striker, instruction_list) || \
		optimizer_striker_look_for_targets(striker))
	{
		return (NOTHING_TO_OPTIMIZE);
	}
	striker->hits = instruction_list;
	while (striker->amount_of_consecutive_hits > \
		striker->amount_of_consecutive_inverse_hits)
	{
		striker->amount_of_consecutive_hits--;
		striker->hits = striker->hits->next;
	}
	amount_of_hits = striker->amount_of_consecutive_hits * 2;
	while (amount_of_hits > 0)
	{
		tmp = striker->hits->next;
		striker->hits->next = tmp->next;
		free(tmp);
		amount_of_hits--;
	}
	return (OPTIMIZE_POSSIBLE);
}
