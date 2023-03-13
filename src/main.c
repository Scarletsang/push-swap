/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/03/13 23:15:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/push_swap.h"

void	test_stack_operations(t_push_swap_2stacks *two_stacks)
{
	print_two_stacks(two_stacks);
	rotate(&two_stacks->stack_a);
	print_two_stacks(two_stacks);
	reverse_rotate(&two_stacks->stack_a);
	print_two_stacks(two_stacks);
	swap(&two_stacks->stack_a);
	print_two_stacks(two_stacks);
	push(&two_stacks->stack_a, &two_stacks->stack_b);
	print_two_stacks(two_stacks);
}

void	test_emulation_indexing(t_push_swap_2stacks *two_stacks, \
t_push_swap_sorter *sorter)
{
	emulate_two_stacks(sorter, two_stacks, RANGE_FROM_MINUS_1, TRIANGLE_SIZE_5);
	print_stack_elements(&sorter->emulation.stack_a);
	print_stack_elements(&two_stacks->stack_a);
}

void	test_naive_triangle_creation(t_push_swap_2stacks *two_stacks, \
t_push_swap_sorter *sorter)
{
	sort_size_of(sorter, two_stacks, two_stacks->stack_a.size);
	print_instructions(sorter);
	print_two_stacks(two_stacks);
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
	t_push_swap_sorter	sorter;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	if (init_program(&two_stacks, argc, argv) || init_sorter(&sorter))
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	ft_printf("-----------\n");
	// test_naive_triangle_creation(&two_stacks, &sorter);
	test_emulation_indexing(&two_stacks, &sorter);
	// print_all_triangles_merge(atoi(argv[1]));
	// test_stack_operations(&two_stacks);
	free_sorter_internals(&sorter);
	free_two_stacks(&two_stacks);
	return (EXIT_SUCCESS);
}
