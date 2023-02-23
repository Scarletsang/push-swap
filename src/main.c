/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/02/23 23:37:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"
#include "PUSH_SWAP/parser.h"

void	test(t_push_swap_sorter *sorter)
{
	// rotate(&sorter.stack_a);
	print_stack_info(&sorter->stack_a);
	print_stack_elements(&sorter->stack_a);
	// print_stacks(&sorter);
	// rotate(&sorter.stack_a);
	// print_stacks(&sorter);
	swap(&sorter->stack_a);
	print_stack_info(&sorter->stack_a);
	print_stack_elements(&sorter->stack_a);
	// print_stacks(&sorter);
	// reverse_rotate(&sorter.stack_a);
	// print_stacks(&sorter);
	// push(&sorter.stack_b, &sorter.stack_a);
	// print_stacks(&sorter);
	// push(&sorter.stack_b, &sorter.stack_a);
	// print_stacks(&sorter);
	free(sorter->stack_a.elements);
	free(sorter->stack_b.elements);
}

int	main(int argc, const char **argv)
{
	t_push_swap_sorter	sorter;
	t_push_swap_parser	parser;
	size_t				size;
	int					*elements;

	elements = to_array(parse_from_cli(&parser, argc, argv), &size);
	if (!elements || init_sorter(&sorter, size, elements))
	{
		ft_printf("Error\n");
		return (EXIT_FAILURE);
	}
	test(&sorter);
	return (EXIT_SUCCESS);
}
