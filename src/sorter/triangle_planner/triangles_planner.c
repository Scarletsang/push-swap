/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_planner.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:50:53 by htsang            #+#    #+#             */
/*   Updated: 2023/03/11 19:29:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_planner.h"

static unsigned int	get_triangle_order(unsigned int triangle_index, \
unsigned int dimension)
{
	unsigned int	layer;
	unsigned int	triangle_index_in_layer;
	unsigned int	pow;

	layer = 1;
	triangle_index_in_layer = triangle_index;
	while (triangle_index_in_layer % 3 == 1)
	{
		dimension--;
		layer *= 3;
		triangle_index_in_layer = triangle_index / layer;
	}
	pow = (dimension != 0);
	while (dimension > 1)
	{
		pow *= 3;
		dimension--;
	}
	return (pow + triangle_index_in_layer - \
		get_important_triangles_before(triangle_index, layer * 3));
}

static unsigned int	get_triangle_size(unsigned int triangle_index, \
t_push_swap_triangles_planner *planner, \
t_push_swap_triangles_calculator *calculator)
{
	unsigned int	triangle_order;

	if (calculator->fill_mode == FILL_ALL_EVENLY)
		return (planner->mininum_triangle_size);
	if (calculator->fill_mode == FILL_IMPORTANT_FIRST)
	{
		if ((triangle_index % 3) != 1)
			return (planner->mininum_triangle_size);
		triangle_order = get_triangle_order(triangle_index, \
			planner->triangle_dimension);
		if (triangle_order < calculator->first_partially_filled_triangle)
			return (planner->mininum_triangle_size + \
				planner->triangles_size_delta);
		if (triangle_order == calculator->first_partially_filled_triangle)
			return (calculator->target_triangle_size);
		return (planner->mininum_triangle_size);
	}
	if ((triangle_index % 3) == 1)
		return (planner->mininum_triangle_size + planner->triangles_size_delta);
	triangle_order = get_triangle_order(triangle_index, \
		planner->triangle_dimension);
	triangle_order -= (planner->total_triangles / 3);
	if (triangle_order < calculator->first_partially_filled_triangle)
		return (calculator->target_triangle_size + 1);
	return (calculator->target_triangle_size);
}

void	merge_triangles(t_push_swap_triangles_planner *planner)
{
	unsigned int	new_total_triangles;
	unsigned int	triangle_index;
	unsigned int	last_triangle_index;

	new_total_triangles = planner->total_triangles / 3;
	triangle_index = 0;
	last_triangle_index = planner->total_triangles - 1;
	while (triangle_index < new_total_triangles)
	{
		planner->triangles[triangle_index] += \
			planner->triangles[last_triangle_index] + \
			planner->triangles[last_triangle_index - new_total_triangles];
		triangle_index++;
		last_triangle_index--;
	}
	planner->total_triangles = new_total_triangles;
	planner->mininum_triangle_size *= 3;
	planner->triangles_size_delta *= 3;
}

void	fill_triangles(t_push_swap_triangles_planner *planner)
{
	unsigned int						triangle_index;
	unsigned int						last_triangle_index;
	t_push_swap_triangles_calculator	calculator;

	triangle_index = 0;
	last_triangle_index = planner->total_triangles - 1;
	init_triangles_filler(planner, &calculator);
	while (triangle_index <= last_triangle_index)
	{
		planner->triangles[last_triangle_index - triangle_index] \
			= get_triangle_size(triangle_index, planner, &calculator);
		triangle_index++;
	}
}

int	init_triangles_planner(t_push_swap_triangles_planner *planner, \
unsigned int total_elements)
{
	*((unsigned int *) &planner->total_elements) = total_elements;
	planner->triangles = malloc(sizeof(unsigned int) * total_elements);
	if (!planner->triangles)
	{
		return (EXIT_FAILURE);
	}
	planner->total_triangles = get_total_triangles(total_elements);
	planner->triangle_dimension = get_triangle_dimension(\
		planner->total_triangles);
	planner->mininum_triangle_size = 2;
	planner->triangles_size_delta = 4;
	return (EXIT_SUCCESS);
}
