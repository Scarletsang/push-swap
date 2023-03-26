/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:35:59 by htsang            #+#    #+#             */
/*   Updated: 2023/03/26 16:13:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/parser.h"

int	add_collector(t_push_swap_cli_parser *parser, int value)
{
	parser->last->next = new_collector(value);
	if (!parser->last->next)
	{
		return (EXIT_FAILURE);
	}
	parser->last = parser->last->next;
	parser->length->value++;
	return (EXIT_SUCCESS);
}

int	init_push_swap_parser(t_push_swap_cli_parser *parser)
{
	parser->length = new_collector(0);
	if (!parser->length)
	{
		return (EXIT_FAILURE);
	}
	parser->last = parser->length;
	return (EXIT_SUCCESS);
}
