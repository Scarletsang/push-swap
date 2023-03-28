/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:21:33 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 02:18:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/shared.h"

int	is_sorted(t_push_swap_2stacks *two_stacks)
{
	int				last_element_value;
	int				current_element_value;
	unsigned int	i;

	if (two_stacks->stack_b.size != 0)
	{
		return (0);
	}
	i = 0;
	last_element_value = get_element_by_index(&two_stacks->stack_a, i);
	while (++i < two_stacks->stack_a.size)
	{
		current_element_value = get_element_by_index(&two_stacks->stack_a, i);
		if (last_element_value > current_element_value)
		{
			return (0);
		}
		last_element_value = current_element_value;
	}
	return (1);
}

int	init_program(t_push_swap_2stacks *two_stacks, int argc, \
const char **argv)
{
	t_push_swap_cli_parser	parser;
	unsigned int			size;
	int						*elements;

	elements = to_array(parse_from_cli(&parser, argc, argv), &size);
	return (!elements || init_two_stacks(two_stacks, size, elements));
}
