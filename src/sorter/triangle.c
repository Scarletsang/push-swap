/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:06:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/03 03:50:46 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

static t_push_swap_triangle_shape	switch_triangle_shape(\
t_push_swap_triangle_shape triangle_shape)
{
	return (triangle_shape != DESCENDING_TRIANGLE);
}

static unsigned int	safe_minus(unsigned int a, unsigned int b)
{
	if (a > b)
	{
		return (a - b);
	}
	return (b - a);
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
t_push_swap_triangles_maker *triangles)
{
	if (triangles->triangle_base_size == 6 || \
		triangles->largest_triangles_amount == 1)
	{
		return (triangles->triangle_base_size);
	}
	if (index == triangles->mid_index)
	{
		return (triangles->triangle_base_size + \
			(1 * (triangles->remainder % 2 == 1)));
	}
	if (((safe_minus(index, triangles->mid_index) * 2) \
		<= triangles->remainder))
	{
		return (triangles->triangle_base_size + 1);
	}
	return (triangles->triangle_base_size);
}

t_push_swap_triangle_shape	get_triangle_shape(unsigned int index, \
unsigned int largest_triangles_amount)
{
	unsigned int	triangles_amount;
	unsigned int	triangle_shape;

	triangles_amount = 1;
	triangle_shape = ASCENDING_TRIANGLE;
	while (triangles_amount < largest_triangles_amount)
	{
		if (((index / triangles_amount) + 1) % 3 == 0)
		{
			return (triangle_shape);
		}
		else if ((index / triangles_amount) % 3 == 0)
		{
			return (switch_triangle_shape(triangle_shape));
		}
		triangle_shape = switch_triangle_shape(triangle_shape);
		triangles_amount *= 3;
	}
	return (triangle_shape);
}
