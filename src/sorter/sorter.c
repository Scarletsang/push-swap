/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:38:05 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 14:23:11 by htsang           ###   ########.fr       */
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
		prepare_emulation(&triangle_maker, planner->triangles[triangle_index], \
			get_triangle_shape(triangle_index, planner->total_triangles));
		emulate_two_stacks(&triangle_maker, two_stacks);
		if (create_triangle(&emulation_instructor, &triangle_maker, \
			triangle_index == (planner->total_triangles - 1)))
		{
			free_instruction_list(emulation_instructor.cost);
			return (free_two_stacks(&triangle_maker.emulation), FAILURE);
		}
		concat_instructor(instructor, &emulation_instructor);
		execute_unexecuted_instructions(instructor);
		triangle_index++;
	}
	free(emulation_instructor.cost);
	return (free_two_stacks(&triangle_maker.emulation), SUCCESS);
}
