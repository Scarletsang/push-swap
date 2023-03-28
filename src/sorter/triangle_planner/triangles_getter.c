/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_getter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 00:39:44 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:49:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_planner.h"

unsigned int	triangles_plannerget_important_triangles_before_index(\
unsigned int triangle_index, unsigned int layer)
{
	unsigned int	first_important_triangle_index;

	first_important_triangle_index = (layer - 1) / 2;
	if (triangle_index >= first_important_triangle_index)
		return (1 + \
			((triangle_index - first_important_triangle_index) / layer));
	return (0);
}

unsigned int	triangles_planner_get_total_triangles(\
unsigned int total_elements)
{
	unsigned int	triangles_amount;

	triangles_amount = 1;
	while (total_elements > (triangles_amount * 6))
	{
		triangles_amount *= 3;
	}
	return (triangles_amount);
}

unsigned int	triangles_planner_get_merge_dimension(\
unsigned int total_triangles)
{
	unsigned int	dimension;

	dimension = 0;
	while (total_triangles != 1)
	{
		dimension++;
		total_triangles /= 3;
	}
	return (dimension);
}
