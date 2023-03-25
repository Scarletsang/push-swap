/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:54:04 by htsang            #+#    #+#             */
/*   Updated: 2023/03/25 23:36:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/optimizer.h"

void	optmize_instructions(t_push_swap_instructor *instructor)
{
	t_push_swap_instruction_list		*optimizer;
	t_push_swap_instruction_striker		striker;
	t_push_swap_instruction_combiner	combiner;

	optimizer = instructor->cost;
	while (optimizer)
	{
		if (strike_down_instructions(&striker, optimizer) \
			== OPTIMIZE_POSSIBLE)
		{
			increase_cost_by(instructor, -2 * \
				striker.amount_of_consecutive_hits);
			optimizer = instructor->cost;
			continue ;
		}
		if (combine_instructions(&combiner, optimizer) \
			== OPTIMIZE_POSSIBLE)
		{
			increase_cost_by(instructor, -1);
			optimizer = instructor->cost;
			continue ;
		}
		optimizer = optimizer->next;
	}
}
