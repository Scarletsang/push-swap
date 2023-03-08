/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:50:53 by htsang            #+#    #+#             */
/*   Updated: 2023/03/08 02:32:43 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

// void	create_(unsigned int total_elements)
// {
// 	unsigned int				index;
// 	t_push_swap_triangles_maker	maker;

// 	init_triangles_maker(&maker, total_elements);
// 	index = 0;
// 	while (index < maker.total_triangles)
// 	{
// 		if (get_triangle_shape(index, maker.total_triangles))
// 			ft_printf("D");
// 		else
// 			ft_printf("A");
// 		ft_printf("(%u) ", get_triangle_size(index, &maker));
// 		if ((index + 1) % 3 == 0)
// 			ft_printf("  ");
// 		if ((index + 1) % 9 == 0)
// 			ft_printf("\n");
// 		if ((index + 1) % 27 == 0)
// 			ft_printf("\n");
// 		index++;
// 	}
// }

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

void	merge_triangles(t_push_swap_triangles_maker *maker, \
t_push_swap_triangles_filler *filler)
{
	maker->total_triangles /= 3;
	maker->mininum_triangle_size *= 3;
	maker->triangles_size_delta *= 3;
	filler->total_important_triangles = get_important_triangles_before(\
		maker->total_triangles - 1, 3);
	filler->triangle_dimension--;
	filler->fill_mode = calculate_fill_mode(maker, filler);
}

void	init_triangles_maker(t_push_swap_triangles_maker *maker, \
t_push_swap_triangles_filler *filler, unsigned int total_elements)
{
	*((unsigned int *) &maker->total_elements) = total_elements;
	maker->total_triangles = get_total_triangles(total_elements);
	maker->mininum_triangle_size = 2;
	maker->triangles_size_delta = 4;
	filler->total_important_triangles = get_important_triangles_before(\
		maker->total_triangles - 1, 3);
	filler->triangle_dimension = get_triangle_dimension(\
		maker->total_triangles);
	filler->fill_mode = calculate_fill_mode(maker, filler);
}
