/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:28:17 by htsang            #+#    #+#             */
/*   Updated: 2023/03/08 19:29:55 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

void	print_triangles(t_push_swap_triangles_maker *maker)
{
	unsigned int	index;

	index = 0;
	while (index < maker->total_triangles)
	{
		if (get_triangle_shape(\
			maker->total_triangles - index, maker->total_triangles))
			ft_printf("D");
		else
			ft_printf("A");
		ft_printf("(%u) ", maker->triangles[index]);
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

int	print_all_triangles_merge(unsigned int total_elements)
{
	t_push_swap_triangles_maker		maker;
	unsigned int					triangle_dimension;

	if (init_triangles_maker(&maker, total_elements))
	{
		return (EXIT_FAILURE);
	}
	fill_triangles(&maker);
	triangle_dimension = maker.triangle_dimension;
	while (triangle_dimension > 0)
	{
		print_triangles(&maker);
		merge_triangles(&maker);
		triangle_dimension--;
	}
	print_triangles(&maker);
	free(maker.triangles);
	return (EXIT_SUCCESS);
}
