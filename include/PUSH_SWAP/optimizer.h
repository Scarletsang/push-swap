/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 22:51:36 by htsang            #+#    #+#             */
/*   Updated: 2023/03/25 00:32:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPTIMIZIER_H
# define OPTIMIZIER_H

# include "PUSH_SWAP/sorter.h"

typedef enum e_push_swap_optimize_possible
{
	OPTIMIZATION_COMPLETE,
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


#endif