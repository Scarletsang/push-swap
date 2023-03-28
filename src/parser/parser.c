/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:59 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:21:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/parser.h"

int	cli_parser_add_collector(t_push_swap_cli_parser *parser, int value)
{
	parser->last->next = collector_create(value);
	if (!parser->last->next)
	{
		return (EXIT_FAILURE);
	}
	parser->last = parser->last->next;
	parser->length->value++;
	return (EXIT_SUCCESS);
}

int	cli_parser_init(t_push_swap_cli_parser *parser)
{
	parser->length = collector_create(0);
	if (!parser->length)
	{
		return (EXIT_FAILURE);
	}
	parser->last = parser->length;
	return (EXIT_SUCCESS);
}
