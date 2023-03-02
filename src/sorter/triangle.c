/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 21:06:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/02 21:41:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

static t_push_swap_triangle_shape	switch_triangle_shape(\
t_push_swap_triangle_shape triangle_shape)
{
	return (triangle_shape != DESCENDING_TRIANGLE);
}

unsigned int	get_triangle_dimension(unsigned int stack_size)
{
	unsigned int	triangle_dimension;

	triangle_dimension = 0;
	while (stack_size > 5)
	{
		stack_size /= 3;
		triangle_dimension++;
	}
	return (triangle_dimension);
}

t_push_swap_triangle_shape	get_triangle_shape(unsigned int index, \
unsigned int triangle_dimension)
{
	unsigned int	triangle_diemension_index;
	unsigned int	triangle_groups_size;
	unsigned int	triangle_shape;

	triangle_diemension_index = 0;
	triangle_groups_size = 1;
	triangle_shape = ASCENDING_TRIANGLE;
	while (triangle_diemension_index < triangle_dimension)
	{
		if (((index / triangle_groups_size) + 1) % 3 == 0)
		{
			return (triangle_shape);
		}
		else if ((index / triangle_groups_size) % 3 == 0)
		{
			return (switch_triangle_shape(triangle_shape));
		}
		triangle_shape = switch_triangle_shape(triangle_shape);
		triangle_groups_size *= 3;
		triangle_diemension_index++;
	}
	return (triangle_shape);
}
