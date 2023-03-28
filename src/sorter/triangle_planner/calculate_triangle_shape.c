/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_triangle_shape.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 05:59:18 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:59:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_planner.h"

int	triangle_shape_ascending(int element_a, int element_b)
{
	return (element_a < element_b);
}

int	triangle_shape_descending(int element_a, int element_b)
{
	return (element_a > element_b);
}

t_push_swap_triangle_shape	triangle_shape_switch(\
t_push_swap_triangle_shape triangle_shape)
{
	if (triangle_shape == &triangle_shape_ascending)
		return (&triangle_shape_descending);
	return (&triangle_shape_ascending);
}

t_push_swap_triangle_shape	triangles_planner_calculate_triangle_shape(\
unsigned int triangle_index, unsigned int total_triangles, \
const unsigned int triangle_dimension)
{
	t_push_swap_triangle_shape	triangle_shape;
	unsigned int				triangles_amount;
	unsigned int				determinant;

	triangles_amount = 1;
	if (((triangle_dimension % 2) == 1) || (triangle_dimension == 0))
		triangle_shape = &triangle_shape_ascending;
	else
		triangle_shape = &triangle_shape_descending;
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
			return (triangle_shape_switch(triangle_shape));
		}
		triangle_shape = triangle_shape_switch(triangle_shape);
		triangles_amount *= 3;
	}
	return (triangle_shape);
}
