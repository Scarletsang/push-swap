/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:51:36 by htsang            #+#    #+#             */
/*   Updated: 2023/03/25 23:43:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZER_H
# define OPTIMIZER_H

# include "PUSH_SWAP/sorter.h"

typedef enum e_push_swap_optimize_possible
{
	OPTIMIZE_POSSIBLE,
	NOTHING_TO_OPTIMIZE
}				t_push_swap_optimize_possible;

typedef struct s_push_swap_instruction_striker
{
	t_push_swap_instruction_list	*hits;
	t_push_swap_instruction			target;
	t_push_swap_instruction			inverse_target;
	unsigned int					amount_of_consecutive_hits;
	unsigned int					amount_of_consecutive_inverse_hits;
}				t_push_swap_instruction_striker;

typedef struct s_push_swap_instruction_combiner
{
	t_push_swap_instruction	look_for;
	t_push_swap_instruction	into;
}				t_push_swap_instruction_combiner;

t_push_swap_optimize_possible	strike_down_instructions(\
t_push_swap_instruction_striker *striker, \
t_push_swap_instruction_list *instruction_list);

t_push_swap_optimize_possible	combine_instructions(\
t_push_swap_instruction_combiner *combiner, \
t_push_swap_instruction_list *instruction_list);

void							optmize_instructions(\
t_push_swap_instructor *instructor);

#endif