/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_planner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:50:53 by htsang            #+#    #+#             */
/*   Updated: 2023/04/27 15:17:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_planner.h"

void	triangles_planner_merge(t_push_swap_triangles_planner *planner)
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

int	triangles_planner_init(t_push_swap_triangles_planner *planner, \
unsigned int total_elements)
{
	*((unsigned int *) &planner->total_elements) = total_elements;
	planner->triangles_size = malloc(sizeof(unsigned int) * total_elements);
	if (!planner->triangles_size)
	{
		return (EXIT_FAILURE);
	}
	planner->total_triangles = \
		triangles_planner_get_total_triangles(total_elements);
	*((unsigned int *) &planner->merge_dimension) = \
		triangles_planner_get_merge_dimension(planner->total_triangles);
	planner->mininum_triangle_size = 2;
	planner->triangles_size_delta = 4;
	return (EXIT_SUCCESS);
}
