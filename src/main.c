/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:36:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/shared.h"
#include "PUSH_SWAP/sorter.h"
#include "PUSH_SWAP/optimizer.h"

int	main(int argc, const char **argv)
{
	t_push_swap_sorter	sorter;

	if (argc < 2)
	{
		return (EXIT_FAILURE);
	}
	if (two_stacks_init_from_cli(&sorter.two_stacks, argc, argv) || \
		instructor_init(&sorter.instructor, &sorter.two_stacks) || \
		init_triangles_planner(&sorter.planner, sorter.two_stacks.stack_a.size))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (EXIT_FAILURE);
	}
	if (two_stacks_is_sorted(&sorter.two_stacks))
		return (EXIT_SUCCESS);
	precalculate_all_triangles_size(&sorter.planner);
	if (sorter_create_all_triangles(&sorter))
		return (sorter_free(&sorter));
	merger_init(&sorter.merger, &sorter.two_stacks);
	if (sorter_merge_triangles_till_sorted(&sorter))
		return (sorter_free(&sorter));
	optimizer_optmize_instructions(&sorter.instructor);
	instructor_print(&sorter.instructor);
	sorter_free(&sorter);
	return (EXIT_SUCCESS);
}
