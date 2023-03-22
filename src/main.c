/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 15:33:36 by htsang           ###   ########.fr       */
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
	t_push_swap_sorter	sorter;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	if (init_program(&sorter.two_stacks, argc, argv) || \
		init_instructor(&sorter.instructor, &sorter.two_stacks) || \
		init_triangles_planner(&sorter.planner, sorter.two_stacks.stack_a.size))
	{
		write(STDERR_FILENO, "Error\n", 7);
		return (EXIT_FAILURE);
	}
	precalculate_all_triangles_size(&sorter.planner);
	print_triangles(&sorter.planner);
	create_all_triangles(&sorter);
	print_instructions(&sorter.instructor);
	ft_printf("Cost: %d\n", get_cost(&sorter.instructor));
	print_two_stacks(&sorter.two_stacks);
	free_two_stacks(&sorter.two_stacks);
	free(sorter.planner.triangles);
	free_instruction_list(sorter.instructor.cost);
	return (EXIT_SUCCESS);
}
