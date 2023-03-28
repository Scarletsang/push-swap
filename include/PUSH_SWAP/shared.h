/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 02:23:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

# include "PUSH_SWAP/parser.h"
# include "PUSH_SWAP/stack.h"
# include <unistd.h>

////////////////////////////////////////
////////    Shared interface    ////////
////////////////////////////////////////

/**
 * This is a small collection of functions that are shared by the checker
 * and the main push swap program.
*/

/**
 * @brief Check if the two stacks are sorted. It is only sorted if elements
 * are arranged in ascending order in stack_a and stack_b is empty.
 * @param two_stacks The two stacks
 * @return 1 if it is sorted, otherwise 0
 */
int	is_sorted(t_push_swap_2stacks *two_stacks);

/**
 * @brief Parse input from command line arguments, and store it in the two
 * stacks.
 * @param two_stacks The two stacks
 * @param argc argc from main()
 * @param argv argv from main()
 * @return 0 if nothing failed. 1 if parse fails, or any malloc() call fails.
 */
int	init_program(t_push_swap_2stacks *two_stacks, int argc, \
const char **argv);

#endif