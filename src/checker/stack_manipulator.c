/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_manipulator.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 21:34:59 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:26:34 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/checker.h"

int	checker_parse_and_run_operation(t_push_swap_2stacks *two_stacks, char *str)
{
	if (checker_parse_push(two_stacks, &str) && \
		checker_parse_swap(two_stacks, &str) && \
		checker_parse_rotate(two_stacks, &str))
	{
		return (EXIT_FAILURE);
	}
	if (*str == '\n')
	{
		return (EXIT_SUCCESS);
	}
	return (EXIT_FAILURE);
}

int	checker_manipulate_stacks_from_fd(t_push_swap_2stacks *two_stacks, int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		if (checker_parse_and_run_operation(two_stacks, str))
		{
			free(str);
			return (EXIT_FAILURE);
		}
		free(str);
		str = get_next_line(fd);
	}
	return (EXIT_SUCCESS);
}
