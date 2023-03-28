/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:51:36 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:22:13 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZER_H
# define OPTIMIZER_H

# include "PUSH_SWAP/sorter.h"

/**
 * @brief This type is an identifier to whether an optimizer found
 * optimization at the instruction sequence it is looking at.
 */
typedef enum e_push_swap_optimize_possible
{
	OPTIMIZE_POSSIBLE,
	NOTHING_TO_OPTIMIZE
}				t_push_swap_optimize_possible;

///////////////////////////////////////////////
////////    The instruction striker    ////////
///////////////////////////////////////////////

/**
 * @brief The instruction striker knock down instructions sequences
 * that does nothing, like {ra, rra}, {sa, sa}, {pa, pb} etc.
 */
typedef struct s_push_swap_instruction_striker
{
	t_push_swap_instruction_list	*hits;
	t_push_swap_instruction			target;
	t_push_swap_instruction			inverse_target;
	unsigned int					amount_of_consecutive_hits;
	unsigned int					amount_of_consecutive_inverse_hits;
}				t_push_swap_instruction_striker;

t_push_swap_optimize_possible	optimizer_strike_down_instructions(\
t_push_swap_instruction_striker *striker, \
t_push_swap_instruction_list *instruction_list);

////////////////////////////////////////////////
////////    The instruction combiner    ////////
////////////////////////////////////////////////

/**
 * @brief The instruction combiner combine {ra, rb} into rr,
 * {rra, rrb} into rrr, and {sa, sb} into ss.
 */
typedef struct s_push_swap_instruction_combiner
{
	t_push_swap_instruction	look_for;
	t_push_swap_instruction	into;
}				t_push_swap_instruction_combiner;

t_push_swap_optimize_possible	optimizer_combine_instructions(\
t_push_swap_instruction_combiner *combiner, \
t_push_swap_instruction_list *instruction_list);

/////////////////////////////////////
////////    The optimizer    ////////
/////////////////////////////////////

void							optimizer_optmize_instructions(\
t_push_swap_instructor *instructor);

#endif