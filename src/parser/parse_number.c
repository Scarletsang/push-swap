/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:48:44 by htsang            #+#    #+#             */
/*   Updated: 2023/03/23 23:55:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/parser.h"
#include <limits.h>

static int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

static int	parse_negative_digits(const char **str, int *result, \
int has_digits)
{
	while (**str && ft_isdigit(**str))
	{
		has_digits = EXIT_SUCCESS;
		if (*result >= (INT_MIN + (**str - '0')) / 10)
		{
			*result = *result * 10 - (**str - '0');
			(*str)++;
			continue ;
		}
		return (EXIT_FAILURE);
	}
	if ((**str != '\0') && (**str != ' '))
	{
		return (EXIT_FAILURE);
	}
	return (has_digits);
}

static int	parse_positive_digits(const char **str, int *result, \
int has_digits)
{
	while (**str && ft_isdigit(**str))
	{
		has_digits = EXIT_SUCCESS;
		if (*result <= (INT_MAX - (**str - '0')) / 10)
		{
			*result = *result * 10 + (**str - '0');
			(*str)++;
			continue ;
		}
		return (EXIT_FAILURE);
	}
	if ((**str != '\0') && (**str != ' '))
	{
		return (EXIT_FAILURE);
	}
	return (has_digits);
}

int	parse_number(const char **str, int *result)
{
	int	positive;
	int	has_digits;

	*result = 0;
	positive = 1;
	has_digits = EXIT_SUCCESS;
	if ((**str == '-') || (**str == '+'))
	{
		has_digits = EXIT_FAILURE;
		if (**str == '-')
			positive = 0;
		(*str)++;
	}
	if (!positive)
	{
		return (parse_negative_digits(str, result, has_digits));
	}
	return (parse_positive_digits(str, result, has_digits));
}
