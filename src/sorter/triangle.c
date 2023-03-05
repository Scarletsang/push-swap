/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:06:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/05 21:02:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

static t_push_swap_triangle_shape	switch_triangle_shape(\
t_push_swap_triangle_shape triangle_shape)
{
	return (triangle_shape != DESCENDING_TRIANGLE);
}

unsigned int	get_largest_triangles_amount(unsigned int stack_size)
{
	unsigned int	triangles_amount;

	triangles_amount = 1;
	while (stack_size > (triangles_amount * 6))
	{
		triangles_amount *= 3;
	}
	return (triangles_amount);
}

unsigned int	get_triangle_size(unsigned int index, \
t_push_swap_triangles_maker *maker)
{
	unsigned int	priority;
	unsigned int	triangles_amount;

	triangles_amount = 1;
	priority = 0;
	if (maker->remainder == maker->largest_triangles_amount)
		return (maker->mininum_triangle_size);
	while (triangles_amount < maker->largest_triangles_amount)
	{
		if (((index / triangles_amount) % 3) != 1)
		{
			if ()
			{
				return (maker->mininum_triangle_size + \
					(maker->remainder % maker->triangles_size_delta));
			}
			return (maker->mininum_triangle_size);
		}
		priority++;
		triangles_amount *= 3;
	}
	return (maker->mininum_triangle_size + \
		(maker->remainder % maker->triangles_size_delta));
}

t_push_swap_triangle_shape	get_triangle_shape(unsigned int index, \
unsigned int largest_triangles_amount)
{
	t_push_swap_triangle_shape	triangle_shape;
	unsigned int				triangles_amount;
	unsigned int				determinant;

	triangles_amount = 1;
	triangle_shape = ASCENDING_TRIANGLE;
	while (triangles_amount < largest_triangles_amount)
	{
		determinant = (index / triangles_amount) % 3;
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
