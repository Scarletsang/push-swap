/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:48:44 by htsang            #+#    #+#             */
/*   Updated: 2023/02/24 18:15:14 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/parser.h"
#include <limits.h>

static int	ft_isdigit(int c)
{
	return (c > 47 && c < 58);
}

static int	parse_negative_digits(const char **str, int *result)
{
	while (**str && ft_isdigit(**str))
	{
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
	return (EXIT_SUCCESS);
}

static int	parse_positive_digits(const char **str, int *result)
{
	while (**str && ft_isdigit(**str))
	{
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
	return (EXIT_SUCCESS);
}

int	parse_number(const char **str, int *result)
{
	int	positive;

	*result = 0;
	positive = 1;
	if (**str == '-')
		positive = 0;
	if (**str == '-' || **str == '+')
		(*str)++;
	if (!positive)
	{
		return (parse_negative_digits(str, result));
	}
	return (parse_positive_digits(str, result));
}
