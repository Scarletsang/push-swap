/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 21:38:05 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 15:15:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

t_push_swap_error_code	create_all_triangles(t_push_swap_sorter *sorter)
{
	t_push_swap_instructor		emulation_instructor;
	t_push_swap_triangle_maker	triangle_maker;
	unsigned int				triangle_index;

	if (init_triangle_maker(&emulation_instructor, &triangle_maker))
		return (FAILURE);
	triangle_index = 0;
	while (triangle_index < sorter->planner.total_triangles)
	{
		prepare_emulation(&triangle_maker, \
			sorter->planner.triangles[triangle_index], get_triangle_shape(\
				triangle_index, sorter->planner.total_triangles));
		emulate_two_stacks(&triangle_maker, &sorter->two_stacks);
		if (create_triangle(&emulation_instructor, &triangle_maker, \
			triangle_index == (sorter->planner.total_triangles - 1)))
		{
			free_instruction_list(emulation_instructor.cost);
			return (free_two_stacks(&triangle_maker.emulation), FAILURE);
		}
		concat_instructor(&sorter->instructor, &emulation_instructor);
		execute_unexecuted_instructions(&sorter->instructor);
		triangle_index++;
	}
	free(emulation_instructor.cost);
	return (free_two_stacks(&triangle_maker.emulation), SUCCESS);
}
