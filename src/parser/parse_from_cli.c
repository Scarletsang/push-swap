/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_from_cli.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 22:30:05 by htsang            #+#    #+#             */
/*   Updated: 2023/02/25 19:59:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/parser.h"

static void	ignore_space(const char **str)
{
	while (**str == ' ')
	{
		(*str)++;
	}
}

static int	has_duplicates(t_push_swap_parser *parser, int value)
{
	t_push_swap_parser_collector	*collector;

	collector = parser->length->next;
	while (collector)
	{
		if (collector->value == value)
		{
			return (1);
		}
		collector = collector->next;
	}
	return (0);
}

static int	parse_numbers(const char *str, t_push_swap_parser *parser)
{
	int	value;

	while (*str)
	{
		ignore_space(&str);
		if (parse_number(&str, &value) || has_duplicates(parser, value))
		{
			return (EXIT_FAILURE);
		}
		if (add_collector(parser, value))
		{
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

t_push_swap_parser	*parse_from_cli(t_push_swap_parser *parser, int argc, \
const char **argv)
{
	int	i;

	if (init_push_swap_parser(parser))
	{
		return (NULL);
	}
	i = 1;
	while (i < argc)
	{
		ignore_space(&argv[i]);
		if (parse_numbers(argv[i], parser))
		{
			clean_collectors(parser->length);
			return (NULL);
		}
		i++;
	}
	if (parser->length == parser->last)
	{
		free(parser->length);
		return (NULL);
	}
	return (parser);
}

int	*to_array(t_push_swap_parser *parser, size_t *size)
{
	int								*array;
	int								i;
	t_push_swap_parser_collector	*collector;

	if (parser == NULL)
	{
		return (NULL);
	}
	*size = parser->length->value;
	array = malloc(sizeof(int) * *size);
	if (!array)
	{
		clean_collectors(parser->length);
		return (NULL);
	}
	i = 0;
	collector = parser->length->next;
	while (collector)
	{
		array[i++] = collector->value;
		collector = collector->next;
	}
	clean_collectors(parser->length);
	return (array);
}
