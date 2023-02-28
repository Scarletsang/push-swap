/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:34:59 by htsang            #+#    #+#             */
/*   Updated: 2023/02/27 23:56:04 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/checker.h"

int	parse_and_run_operation(t_push_swap_2stacks *two_stacks, char *str)
{
	if (parse_push(two_stacks, &str) && \
		parse_swap(two_stacks, &str) && \
		parse_rotate(two_stacks, &str))
	{
		return (EXIT_FAILURE);
	}
	if (*str == '\n')
	{
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	manipulate_stacks_from_fd(t_push_swap_2stacks *two_stacks, int fd)
{
	char	*str;

	print_two_stacks(two_stacks);
	str = get_next_line(fd);
	while (str)
	{
		if (parse_and_run_operation(two_stacks, str))
		{
			free(str);
			return (EXIT_FAILURE);
		}
		print_two_stacks(two_stacks);
		free(str);
		str = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}
