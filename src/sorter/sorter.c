/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:38:05 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 00:03:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

t_push_swap_error_code	create_all_triangles(\
t_push_swap_2stacks *two_stacks, \
t_push_swap_triangles_planner *planner, t_push_swap_instructor *instructor)
{
	t_push_swap_instructor		emulation_instructor;
	t_push_swap_triangle_maker	triangle_maker;
	unsigned int				triangle_index;

	if (init_triangle_maker(&emulation_instructor, &triangle_maker))
		return (FAILURE);
	triangle_index = 0;
	while (triangle_index < planner->total_triangles)
	{
		prepare_emulation(&triangle_maker, \
			planner->triangles[triangle_index], \
			get_triangle_shape(planner->total_triangles - 1 - triangle_index, \
				planner->total_triangles));
		emulate_two_stacks(&triangle_maker, two_stacks);
		print_instructions(&emulation_instructor);
		print_two_stacks(&triangle_maker.emulation);
		if (create_triangle(&emulation_instructor, &triangle_maker))
		{
			free_instruction_list(emulation_instructor.cost);
			free_two_stacks(&triangle_maker.emulation);
			return (FAILURE);
		}
		print_instructions(&emulation_instructor);
		print_two_stacks(&triangle_maker.emulation);
		concat_instructor(instructor, &emulation_instructor);
		execute_unexecuted_instructions(instructor);
		triangle_index++;
	}
	free_two_stacks(&triangle_maker.emulation);
	return (SUCCESS);
}
