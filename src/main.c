/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 04:40:48 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/push_swap.h"

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
	create_all_triangles(&two_stacks, &planner, &instructor);
	print_triangles(&planner);
	print_instructions(&instructor);
	print_two_stacks(&two_stacks);
	free_instruction_list(instructor.cost);
	free_two_stacks(&two_stacks);
	return (EXIT_SUCCESS);
}
