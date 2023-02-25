/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/26 00:18:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "PUSH_SWAP/parser.h"
# include "PUSH_SWAP/stack.h"
# include "GET_NEXT_LINE/get_next_line.h"

int	parse_swap(t_push_swap_2stacks *two_stacks, char **str);

int	parse_push(t_push_swap_2stacks *two_stacks, char **str);

int	parse_rotate(t_push_swap_2stacks *two_stacks, char **str);

int	manipulate_stacks_from_fd(t_push_swap_2stacks *two_stacks, int fd);

int	is_sorted(t_push_swap_2stacks *two_stacks);

#endif