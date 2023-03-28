/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:12:55 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:26:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/checker.h"

static int	checker_matches_char(char **str, char expected)
{
	if (**str == expected)
	{
		(*str)++;
		return (1);
	}
	return (0);
}

int	checker_parse_swap(t_push_swap_2stacks *two_stacks, char **str)
{
	if (checker_matches_char(str, 's'))
	{
		if (checker_matches_char(str, 'a'))
		{
			return (swap(&two_stacks->stack_a));
		}
		if (checker_matches_char(str, 'b'))
		{
			return (swap(&two_stacks->stack_b));
		}
		if (checker_matches_char(str, 's'))
		{
			swap(&two_stacks->stack_a);
			return (swap(&two_stacks->stack_b));
		}
	}
	return (EXIT_FAILURE);
}

int	checker_parse_push(t_push_swap_2stacks *two_stacks, char **str)
{
	if (checker_matches_char(str, 'p'))
	{
		if (checker_matches_char(str, 'a'))
		{
			return (push(&two_stacks->stack_a, &two_stacks->stack_b));
		}
		if (checker_matches_char(str, 'b'))
		{
			return (push(&two_stacks->stack_b, &two_stacks->stack_a));
		}
	}
	return (EXIT_FAILURE);
}

static int	checker_parse_reverse_rotate(t_push_swap_2stacks *two_stacks, \
char **str)
{
	if (checker_matches_char(str, 'a'))
	{
		return (reverse_rotate(&two_stacks->stack_a));
	}
	if (checker_matches_char(str, 'b'))
	{
		return (reverse_rotate(&two_stacks->stack_b));
	}
	if (checker_matches_char(str, 'r'))
	{
		reverse_rotate(&two_stacks->stack_a);
		return (reverse_rotate(&two_stacks->stack_b));
	}
	return (EXIT_FAILURE);
}

int	checker_parse_rotate(t_push_swap_2stacks *two_stacks, char **str)
{
	if (checker_matches_char(str, 'r'))
	{
		if (checker_matches_char(str, 'a'))
		{
			return (rotate(&two_stacks->stack_a));
		}
		if (checker_matches_char(str, 'b'))
		{
			return (rotate(&two_stacks->stack_b));
		}
		if (checker_matches_char(str, 'r'))
		{
			if (**str == '\n')
			{
				rotate(&two_stacks->stack_a);
				return (rotate(&two_stacks->stack_b));
			}
			return (checker_parse_reverse_rotate(two_stacks, str));
		}
	}
	return (EXIT_FAILURE);
}
