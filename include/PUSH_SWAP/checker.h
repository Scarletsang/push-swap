/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:26:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "PUSH_SWAP/stack.h"
# include "GET_NEXT_LINE/get_next_line.h"

//////////////////////////////////////////////////
////////        The checker parser        ////////
//////////////////////////////////////////////////

/**
 * Parse the input string and manipulate the stacks accordingly. If the input
 * string is invalid, return EXIT_FAILURE.
*/

int	checker_parse_swap(t_push_swap_2stacks *two_stacks, char **str);

int	checker_parse_push(t_push_swap_2stacks *two_stacks, char **str);

int	checker_parse_rotate(t_push_swap_2stacks *two_stacks, char **str);

///////////////////////////////////////////
////////        The checker        ////////
///////////////////////////////////////////

/**
 * @brief The checker body. The checker will continously read a line from a file
 * descriptor, and manipulate the stacks accordingly. The only valid input is
 * any one of the 11 instructions: pa, pb, sa, sb, ss, ra, rb, rr, rra, rrb, rrr.
 * If any invalid input is detected, EXIT_FAILURE is returned immediately.
 * @param two_stacks The two stacks
 * @param fd The file descriptor to take core operations from.
 * @return EXIT_SUCCESS if the inputs are all valid. EXIT_FAILURE otherwise.
 */
int	checker_manipulate_stacks_from_fd(t_push_swap_2stacks *two_stacks, int fd);

#endif