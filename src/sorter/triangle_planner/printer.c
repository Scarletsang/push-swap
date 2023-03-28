/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:28:17 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 02:07:33 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_planner.h"
#include "FT_PRINTF/ft_printf.h"

void	print_triangles(t_push_swap_triangles_planner *planner)
{
	unsigned int	index;

	index = 0;
	while (index < planner->total_triangles)
	{
		if (calculate_triangle_shape(index, planner->total_triangles, \
			planner->merge_dimension) == &descending_triangle)
			ft_printf("D");
		else
			ft_printf("A");
		ft_printf("(%u) ", planner->triangles_size[index]);
		if ((index + 1) % 3 == 0)
			ft_printf("  ");
		if ((index + 1) % 9 == 0)
			ft_printf("\n");
		if ((index + 1) % 27 == 0)
			ft_printf("\n");
		index++;
	}
	ft_printf("\n===================\n");
}
