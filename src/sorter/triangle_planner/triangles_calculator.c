/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_calculator.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:36:45 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:52:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_planner.h"

static void	fill_unimportant_evenly(\
t_push_swap_triangles_size_calculator *calculator, \
t_push_swap_triangles_planner *planner)
{
	unsigned int	unimportant_triangles_total_size;
	unsigned int	total_unimportant_triangles;

	unimportant_triangles_total_size = planner->total_elements - \
		(calculator->total_important_triangles * \
		(planner->mininum_triangle_size + planner->triangles_size_delta));
	total_unimportant_triangles = planner->total_triangles - \
		calculator->total_important_triangles;
	calculator->target_triangle_size = \
		unimportant_triangles_total_size / total_unimportant_triangles;
	calculator->first_partially_filled_triangle = \
		unimportant_triangles_total_size % total_unimportant_triangles;
}

static t_push_swap_triangle_fill_mode	calculate_fill_mode(\
t_push_swap_triangles_size_calculator *calculator, \
t_push_swap_triangles_planner *planner)
{
	unsigned int	minimum_triangles_size;

	calculator->target_triangle_size = planner->mininum_triangle_size;
	minimum_triangles_size = planner->total_triangles * \
		planner->mininum_triangle_size;
	if (planner->total_elements == minimum_triangles_size)
	{
		return (FILL_ALL_EVENLY);
	}
	if (planner->total_elements <= (minimum_triangles_size + \
		(planner->triangles_size_delta * \
			calculator->total_important_triangles)))
	{
		calculator->first_partially_filled_triangle = \
			(planner->total_elements - minimum_triangles_size) / \
				planner->triangles_size_delta;
		calculator->target_triangle_size = \
			(planner->total_elements - minimum_triangles_size) % \
				planner->triangles_size_delta + planner->mininum_triangle_size;
		return (FILL_IMPORTANT_FIRST);
	}
	fill_unimportant_evenly(calculator, planner);
	return (FILL_UNIMPORTANT_EVENLY);
}

int	triangles_size_calculator_init(\
t_push_swap_triangles_size_calculator *calculator, \
t_push_swap_triangles_planner *planner)
{
	calculator->total_important_triangles = \
		triangles_plannerget_important_triangles_before_index(\
			planner->total_triangles - 1, 3);
	calculator->fill_mode = calculate_fill_mode(calculator, planner);
	return (EXIT_SUCCESS);
}
