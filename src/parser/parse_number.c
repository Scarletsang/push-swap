/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 05:16:29 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:20:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/parser.h"
#include <limits.h>

static int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

static int	cli_parser_parse_negative_digits(const char **str, \
int *result, int has_digits)
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

static int	cli_parser_parse_positive_digits(const char **str, \
int *result, int has_digits)
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

int	cli_parser_parse_number(const char **str, int *result)
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
		return (cli_parser_parse_negative_digits(str, result, has_digits));
	}
	return (cli_parser_parse_positive_digits(str, result, has_digits));
}
