/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/03/24 01:56:32 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/push_swap.h"

int	free_program(t_push_swap_sorter *sorter)
{
	free_two_stacks(&sorter->two_stacks);
	free(sorter->planner.triangles);
	free_instruction_list(sorter->instructor.cost);
	return (EXIT_FAILURE);
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
	t_push_swap_sorter	sorter;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	if (init_program(&sorter.two_stacks, argc, argv) || \
		init_instructor(&sorter.instructor, &sorter.two_stacks) || \
		init_triangles_planner(&sorter.planner, sorter.two_stacks.stack_a.size))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	if (is_sorted(&sorter.two_stacks))
		return (EXIT_SUCCESS);
	precalculate_all_triangles_size(&sorter.planner);
	if (create_all_triangles(&sorter))
		return (free_program(&sorter));
	init_merger(&sorter);
	if (merge_triangles_till_sorted(&sorter))
		return (free_program(&sorter));
	print_instructions(&sorter.instructor);
	free_program(&sorter);
	return (EXIT_SUCCESS);
}
