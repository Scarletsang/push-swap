/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_shaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:06:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/24 17:36:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_planner.h"

int	ascending_triangle(int element_a, int element_b)
{
	return (element_a < element_b);
}

int	descending_triangle(int element_a, int element_b)
{
	return (element_a > element_b);
}

t_push_swap_triangle_shape	switch_triangle_shape(\
t_push_swap_triangle_shape triangle_shape)
{
	if (triangle_shape == &ascending_triangle)
		return (&descending_triangle);
	return (&ascending_triangle);
}

t_push_swap_triangle_shape	get_triangle_shape(unsigned int triangle_index, \
unsigned int total_triangles, const unsigned int triangle_dimension)
{
	t_push_swap_triangle_shape	triangle_shape;
	unsigned int				triangles_amount;
	unsigned int				determinant;

	triangles_amount = 1;
	if (((triangle_dimension % 2) == 1) || (triangle_dimension == 0))
		triangle_shape = &ascending_triangle;
	else
		triangle_shape = &descending_triangle;
	triangle_index = total_triangles - 1 - triangle_index;
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
