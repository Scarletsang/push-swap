/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/23 16:25:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "PUSH_SWAP/parser.h"
# include "PUSH_SWAP/stack.h"
# include "PUSH_SWAP/sorter.h"
# include <unistd.h>

int	is_sorted(t_push_swap_2stacks *two_stacks);

#endif