/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:05:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/26 16:08:10 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/checker.h"
#include "PUSH_SWAP/push_swap.h"

int	main(int argc, const char **argv)
{
	t_push_swap_2stacks	two_stacks;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	if (init_program(&two_stacks, argc, argv) || \
		manipulate_stacks_from_fd(&two_stacks, STDIN_FILENO))
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	if (is_sorted(&two_stacks))
	{
		write(STDOUT_FILENO, "OK\n", 4);
	}
	else
	{
		write(STDOUT_FILENO, "KO\n", 4);
	}
	return (EXIT_SUCCESS);
}
