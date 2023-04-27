/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/04/27 15:21:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/shared.h"
#include "PUSH_SWAP/sorter.h"
#include "PUSH_SWAP/optimizer.h"

int	main(int argc, const char **argv)
{
	t_push_swap_sorter	sorter;

	if (argc < 2)
		return (EXIT_FAILURE);
	if (two_stacks_init_from_cli(&sorter.two_stacks, argc, argv) || \
		instructor_init(&sorter.instructor, &sorter.two_stacks) || \
		triangles_planner_init(&sorter.planner, sorter.two_stacks.stack_a.size))
	{
		write(STDERR_FILENO, "Error\n", 6);
		return (sorter_free(&sorter));
	}
	if (two_stacks_is_sorted(&sorter.two_stacks))
		return (sorter_free(&sorter), EXIT_SUCCESS);
	triangles_planner_calculate_triangles_sizes(&sorter.planner);
	if (sorter_create_all_triangles(&sorter))
		return (sorter_free(&sorter));
	merger_init(&sorter.merger, &sorter.two_stacks);
	if (sorter_merge_triangles_till_sorted(&sorter))
		return (sorter_free(&sorter));
	optimizer_optmize_instructions(&sorter.instructor);
	instructor_print(&sorter.instructor);
	return (sorter_free(&sorter), EXIT_SUCCESS);
}
