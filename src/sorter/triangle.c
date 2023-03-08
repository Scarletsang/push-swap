/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:06:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/08 02:33:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

static t_push_swap_triangle_shape	switch_triangle_shape(\
t_push_swap_triangle_shape triangle_shape)
{
	return (triangle_shape != DESCENDING_TRIANGLE);
}

unsigned int	get_triangle_order(unsigned int triangle_index, \
unsigned int dimension)
{
	unsigned int	layer;
	unsigned int	triangle_index_in_layer;
	unsigned int	pow;

	layer = 1;
	triangle_index_in_layer = triangle_index / layer;
	while (triangle_index_in_layer % 3 == 1)
	{
		dimension -= 1;
		layer *= 3;
		triangle_index_in_layer = triangle_index / layer;
	}
	if (dimension == 0)
		return (triangle_index_in_layer - \
			get_important_triangles_before(triangle_index, layer * 3));
	pow = 1;
	while (dimension-- > 1)
	{
		pow *= 3;
	}
	return (pow + triangle_index_in_layer - \
			get_important_triangles_before(triangle_index, layer * 3));
}

unsigned int	get_triangle_size(unsigned int triangle_index, \
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
			filler->triangle_dimension);
		if (triangle_order < filler->first_partially_filled_triangle)
			return (maker->mininum_triangle_size + maker->triangles_size_delta);
		if (triangle_order == filler->first_partially_filled_triangle)
			return (filler->target_triangle_size);
		return (maker->mininum_triangle_size);
	}
	if ((triangle_index % 3) == 1)
		return (maker->mininum_triangle_size + maker->triangles_size_delta);
	triangle_order = get_triangle_order(triangle_index, \
		filler->triangle_dimension);
	triangle_order -= (maker->total_triangles / 3);
	if (triangle_order < filler->first_partially_filled_triangle)
		return (filler->target_triangle_size + 1);
	return (filler->target_triangle_size);
}

t_push_swap_triangle_shape	get_triangle_shape(\
unsigned int triangle_index, unsigned int total_triangles)
{
	t_push_swap_triangle_shape	triangle_shape;
	unsigned int				triangles_amount;
	unsigned int				determinant;

	triangles_amount = 1;
	triangle_shape = ASCENDING_TRIANGLE;
	while (triangles_amount < total_triangles)
	{
		determinant = (triangle_index / triangles_amount) % 3;
		if (determinant == 2)
		{
			return (triangle_shape);
		}
		else if (determinant == 0)
		{
			return (switch_triangle_shape(triangle_shape));
		}
		triangle_shape = switch_triangle_shape(triangle_shape);
		triangles_amount *= 3;
	}
	return (triangle_shape);
}
