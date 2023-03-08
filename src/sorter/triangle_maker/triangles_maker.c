/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:50:53 by htsang            #+#    #+#             */
/*   Updated: 2023/03/08 19:30:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

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
t_push_swap_triangles_maker *maker, t_push_swap_triangles_filler *filler)
{
	unsigned int	triangle_order;

	if (filler->fill_mode == FILL_ALL_EVENLY)
		return (maker->mininum_triangle_size);
	if (filler->fill_mode == FILL_IMPORTANT_FIRST)
	{
		if ((triangle_index % 3) != 1)
			return (maker->mininum_triangle_size);
		triangle_order = get_triangle_order(triangle_index, \
			maker->triangle_dimension);
		if (triangle_order < filler->first_partially_filled_triangle)
			return (maker->mininum_triangle_size + maker->triangles_size_delta);
		if (triangle_order == filler->first_partially_filled_triangle)
			return (filler->target_triangle_size);
		return (maker->mininum_triangle_size);
	}
	if ((triangle_index % 3) == 1)
		return (maker->mininum_triangle_size + maker->triangles_size_delta);
	triangle_order = get_triangle_order(triangle_index, \
		maker->triangle_dimension);
	triangle_order -= (maker->total_triangles / 3);
	if (triangle_order < filler->first_partially_filled_triangle)
		return (filler->target_triangle_size + 1);
	return (filler->target_triangle_size);
}

void	merge_triangles(t_push_swap_triangles_maker *maker)
{
	unsigned int	new_total_triangles;
	unsigned int	triangle_index;
	unsigned int	last_triangle_index;

	new_total_triangles = maker->total_triangles / 3;
	triangle_index = 0;
	last_triangle_index = maker->total_triangles - 1;
	while (triangle_index < new_total_triangles)
	{
		maker->triangles[triangle_index] += \
			maker->triangles[last_triangle_index] + \
			maker->triangles[last_triangle_index - new_total_triangles];
		triangle_index++;
		last_triangle_index--;
	}
	maker->total_triangles = new_total_triangles;
	maker->mininum_triangle_size *= 3;
	maker->triangles_size_delta *= 3;
}

void	fill_triangles(t_push_swap_triangles_maker *maker)
{
	unsigned int					triangle_index;
	unsigned int					last_triangle_index;
	t_push_swap_triangles_filler	filler;

	triangle_index = 0;
	last_triangle_index = maker->total_triangles - 1;
	init_triangles_filler(maker, &filler);
	while (triangle_index <= last_triangle_index)
	{
		maker->triangles[last_triangle_index - triangle_index] \
			= get_triangle_size(triangle_index, maker, &filler);
		triangle_index++;
	}
}

int	init_triangles_maker(t_push_swap_triangles_maker *maker, \
unsigned int total_elements)
{
	*((unsigned int *) &maker->total_elements) = total_elements;
	maker->triangles = malloc(sizeof(unsigned int) * total_elements);
	if (!maker->triangles)
	{
		return (EXIT_FAILURE);
	}
	maker->total_triangles = get_total_triangles(total_elements);
	maker->triangle_dimension = get_triangle_dimension(\
		maker->total_triangles);
	maker->mininum_triangle_size = 2;
	maker->triangles_size_delta = 4;
	return (EXIT_SUCCESS);
}
