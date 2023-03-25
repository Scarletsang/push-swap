/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combiner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:53:34 by htsang            #+#    #+#             */
/*   Updated: 2023/03/25 20:44:29 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/optimizer.h"

static t_push_swap_optimize_possible	init_combiner(\
t_push_swap_instruction_combiner *combiner, t_push_swap_instruction instruction)
{
	if ((instruction == PA) || (instruction == PB) || (instruction == SS))
		return (NOTHING_TO_OPTIMIZE);
	if (instruction < 0)
		combiner->into = SS;
	else if (((instruction % 2) == 0) && (instruction >= 4))
		combiner->into = RRR;
	else if (((instruction % 2) == 1) && (instruction < 4))
		combiner->into = RR;
	else
		return (NOTHING_TO_OPTIMIZE);
	if (instruction < combiner->into)
		combiner->look_for = instruction + 2;
	else
		combiner->look_for = instruction - 2;
	return (OPTIMIZE_POSSIBLE);
}

t_push_swap_optimize_possible	combine_instructions(\
t_push_swap_instruction_combiner *combiner, \
t_push_swap_instruction_list *instruction_list)
{
	t_push_swap_instruction_list	*tmp;

	if (!instruction_list->next || !instruction_list->next->next || \
		init_combiner(combiner, instruction_list->next->instruction))
		return (NOTHING_TO_OPTIMIZE);
	if (instruction_list->next->next->instruction == combiner->look_for)
	{
		tmp = instruction_list->next;
		instruction_list->next->next->instruction = combiner->into;
		instruction_list->next = tmp->next;
		free(tmp);
		return (OPTIMIZE_POSSIBLE);
	}
	return (NOTHING_TO_OPTIMIZE);
}
