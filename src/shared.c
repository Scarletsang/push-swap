/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:21:33 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:19:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/shared.h"

int	two_stacks_init_from_cli(t_push_swap_2stacks *two_stacks, int argc, \
const char **argv)
{
	t_push_swap_cli_parser	parser;
	unsigned int			size;
	int						*elements;

	elements = cli_parser_to_array(\
		cli_parser_parse_from_cli(&parser, argc, argv), &size);
	return (!elements || two_stacks_init(two_stacks, size, elements));
}
