/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/03/02 21:47:06 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/push_swap.h"

void	test(t_push_swap_2stacks *two_stacks)
{
	// print_stack_info(&two_stacks->stack_a);
	// print_stack_elements(&two_stacks->stack_a);
	// rotate(&sorter.stack_a);
	print_two_stacks(two_stacks);
	rotate(&two_stacks->stack_a);
	print_two_stacks(two_stacks);
	reverse_rotate(&two_stacks->stack_a);
	print_two_stacks(two_stacks);
	swap(&two_stacks->stack_a);
	print_two_stacks(two_stacks);
	push(&two_stacks->stack_a, &two_stacks->stack_b);
	print_two_stacks(two_stacks);
	// print_stack_info(&sorter->stack_a);
	// print_stack_elements(&sorter->stack_a);
	// print_stacks(&sorter);
	// reverse_rotate(&sorter.stack_a);
	// print_stacks(&sorter);
	// push(&sorter.stack_b, &sorter.stack_a);
	// print_stacks(&sorter);
	// push(&sorter.stack_b, &sorter.stack_a);
	// print_stacks(&sorter);
	free(two_stacks->stack_a.elements);
	free(two_stacks->stack_b.elements);
}

int	init_program(t_push_swap_2stacks *two_stacks, int argc, \
const char **argv)
{
	t_push_swap_parser	parser;
	size_t				size;
	int					*elements;

	elements = to_array(parse_from_cli(&parser, argc, argv), &size);
	return (!elements || init_two_stacks(two_stacks, size, elements));
}

int	main(int argc, const char **argv)
{
	t_push_swap_2stacks	two_stacks;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	if (init_program(&two_stacks, argc, argv))
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	print_triangle_shapes(\
		get_triangle_dimension(two_stacks.stack_a.size));
	test(&two_stacks);
	return (EXIT_SUCCESS);
}
