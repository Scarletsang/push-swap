/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/03/21 23:30:54 by htsang           ###   ########.fr       */
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
	t_push_swap_2stacks				two_stacks;
	t_push_swap_triangles_planner	planner;
	t_push_swap_instructor			instructor;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	if (init_program(&two_stacks, argc, argv) || \
		init_instructor(&instructor, &two_stacks) || \
		init_triangles_planner(&planner, two_stacks.stack_a.size))
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	fill_triangles(&planner);
	// test_naive_triangle_creation(&two_stacks, &instructor);
	// test_emulation_indexing(&two_stacks, &instructor);
	// print_all_triangles_merge(atoi(argv[1]));
	// test_stack_operations(&two_stacks);
	// free_two_stacks(&instructor.emulation);
	create_all_triangles(&two_stacks, &planner, &instructor);
	// print_instructions(&instructor);
	// print_two_stacks(&two_stacks);
	free_instruction_list(instructor.cost);
	free_two_stacks(&two_stacks);
	return (EXIT_SUCCESS);
}
