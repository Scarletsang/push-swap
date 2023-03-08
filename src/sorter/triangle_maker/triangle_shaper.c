/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_shaper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:06:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/08 19:29:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

static t_push_swap_triangle_shape	switch_triangle_shape(\
t_push_swap_triangle_shape triangle_shape)
{
	return (triangle_shape != DESCENDING_TRIANGLE);
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
