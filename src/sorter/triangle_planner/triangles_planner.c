/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_planner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:50:53 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 02:07:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_planner.h"

void	merge_triangles_planner(t_push_swap_triangles_planner *planner)
{
	unsigned int	new_total_triangles;
	unsigned int	triangle_index;
	unsigned int	last_triangle_index;

	new_total_triangles = planner->total_triangles / 3;
	triangle_index = 0;
	last_triangle_index = planner->total_triangles - 1;
	while (triangle_index < new_total_triangles)
	{
		planner->triangles_size[triangle_index] += \
			planner->triangles_size[last_triangle_index] + \
			planner->triangles_size[last_triangle_index - new_total_triangles];
		triangle_index++;
		last_triangle_index--;
	}
	planner->total_triangles = new_total_triangles;
	planner->mininum_triangle_size *= 3;
	planner->triangles_size_delta *= 3;
}

int	init_triangles_planner(t_push_swap_triangles_planner *planner, \
unsigned int total_elements)
{
	*((unsigned int *) &planner->total_elements) = total_elements;
	planner->triangles_size = malloc(sizeof(unsigned int) * total_elements);
	if (!planner->triangles_size)
	{
		return (EXIT_FAILURE);
	}
	planner->total_triangles = get_total_triangles(total_elements);
	*((unsigned int *) &planner->merge_dimension) = \
		get_triangle_dimension(planner->total_triangles);
	planner->mininum_triangle_size = 2;
	planner->triangles_size_delta = 4;
	return (EXIT_SUCCESS);
}
