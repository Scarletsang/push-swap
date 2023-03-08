/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_filler.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:36:45 by htsang            #+#    #+#             */
/*   Updated: 2023/03/08 19:30:02 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

static void	fill_unimportant_evenly(t_push_swap_triangles_maker *maker, \
t_push_swap_triangles_filler *filler)
{
	unsigned int	unimportant_triangles_total_size;
	unsigned int	total_unimportant_triangles;

	unimportant_triangles_total_size = maker->total_elements - \
		(filler->total_important_triangles * \
		(maker->mininum_triangle_size + maker->triangles_size_delta));
	total_unimportant_triangles = maker->total_triangles - \
		filler->total_important_triangles;
	filler->target_triangle_size = \
		unimportant_triangles_total_size / total_unimportant_triangles;
	filler->first_partially_filled_triangle = \
		unimportant_triangles_total_size % total_unimportant_triangles;
}

static t_push_swap_triangle_fill_mode	calculate_fill_mode(\
t_push_swap_triangles_maker *maker, t_push_swap_triangles_filler *filler)
{
	unsigned int	minimum_triangles_size;

	filler->target_triangle_size = maker->mininum_triangle_size;
	minimum_triangles_size = maker->total_triangles * \
		maker->mininum_triangle_size;
	if (maker->total_elements == minimum_triangles_size)
	{
		return (FILL_ALL_EVENLY);
	}
	if (maker->total_elements <= (minimum_triangles_size + \
		(maker->triangles_size_delta * filler->total_important_triangles)))
	{
		filler->first_partially_filled_triangle = \
			(maker->total_elements - minimum_triangles_size) / \
				maker->triangles_size_delta;
		filler->target_triangle_size = \
			(maker->total_elements - minimum_triangles_size) % \
				maker->triangles_size_delta + maker->mininum_triangle_size;
		return (FILL_IMPORTANT_FIRST);
	}
	fill_unimportant_evenly(maker, filler);
	return (FILL_UNIMPORTANT_EVENLY);
}

int	init_triangles_filler(t_push_swap_triangles_maker *maker, \
t_push_swap_triangles_filler *filler)
{
	filler->total_important_triangles = get_important_triangles_before(\
		maker->total_triangles - 1, 3);
	filler->fill_mode = calculate_fill_mode(maker, filler);
	return (EXIT_SUCCESS);
}
