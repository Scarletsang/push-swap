/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:54:04 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:30:49 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/optimizer.h"

void	optimizer_optmize_instructions(t_push_swap_instructor *instructor)
{
	t_push_swap_instruction_list		*optimizer;
	t_push_swap_instruction_striker		striker;
	t_push_swap_instruction_combiner	combiner;

	optimizer = instructor->cost;
	while (optimizer)
	{
		if (optimizer_strike_down_instructions(&striker, optimizer) \
			== OPTIMIZE_POSSIBLE)
		{
			instructor_increase_cost_by(instructor, -2 * \
				striker.amount_of_consecutive_hits);
			optimizer = instructor->cost;
			continue ;
		}
		if (optimizer_combine_instructions(&combiner, optimizer) \
			== OPTIMIZE_POSSIBLE)
		{
			instructor_increase_cost_by(instructor, -1);
			optimizer = instructor->cost;
			continue ;
		}
		optimizer = optimizer->next;
	}
}
