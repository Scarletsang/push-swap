/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:08:45 by htsang            #+#    #+#             */
/*   Updated: 2023/02/21 13:21:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "PUSH_SWAP/stack.h"

typedef struct s_push_swap_sorter
{
    t_push_swap_stack   stack_a;
    t_push_swap_stack   stack_b;
}               t_push_swap_sorter;

int		init_sorter(t_push_swap_sorter *sorter, size_t elements_size);

void	print_stacks(t_push_swap_sorter *sorter);

#endif