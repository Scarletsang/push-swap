/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_from_cli.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 05:16:39 by htsang            #+#    #+#             */
/*   Updated: 2023/04/25 18:39:01 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/parser.h"

static void	cli_parser_ignore_space(const char **str)
{
	while (**str == ' ')
	{
		(*str)++;
	}
}

static int	cli_parser_has_duplicates(t_push_swap_cli_parser *parser, int value)
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

static int	cli_parser_parse_numbers(const char *str, \
t_push_swap_cli_parser *parser)
{
	int	value;

	cli_parser_ignore_space(&str);
	while (*str)
	{
		if (cli_parser_parse_number(&str, &value) || \
			cli_parser_has_duplicates(parser, value))
		{
			return (EXIT_FAILURE);
		}
		if (cli_parser_add_collector(parser, value))
		{
			return (EXIT_FAILURE);
		}
		cli_parser_ignore_space(&str);
	}
	return (EXIT_SUCCESS);
}

t_push_swap_cli_parser	*cli_parser_parse_from_cli(\
t_push_swap_cli_parser *parser, int argc, const char **argv)
{
	int	i;

	if (cli_parser_init(parser))
	{
		return (NULL);
	}
	i = 1;
	while (i < argc)
	{
		cli_parser_ignore_space(&argv[i]);
		if (cli_parser_parse_numbers(argv[i], parser))
		{
			collector_free_all(parser->length);
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

int	*cli_parser_to_array(t_push_swap_cli_parser *parser, unsigned int *size)
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
		collector_free_all(parser->length);
		return (NULL);
	}
	i = 0;
	collector = parser->length->next;
	while (collector)
	{
		array[i++] = collector->value;
		collector = collector->next;
	}
	collector_free_all(parser->length);
	return (array);
}
