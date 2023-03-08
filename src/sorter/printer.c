/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:28:17 by htsang            #+#    #+#             */
/*   Updated: 2023/03/08 02:34:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

void	print_triangle_shapes(unsigned int stack_size)
{
	unsigned int					index;
	int								dimension_index;
	t_push_swap_triangles_maker		maker;
	t_push_swap_triangles_filler	filler;

	init_triangles_maker(&maker, &filler, stack_size);
	dimension_index = filler.triangle_dimension;
	while (dimension_index-- >= 0)
	{
		index = 0;
		while (index < maker.total_triangles)
		{
			if (get_triangle_shape(index, maker.total_triangles))
				ft_printf("D");
			else
				ft_printf("A");
			ft_printf("(%u) ", get_triangle_size(index, &maker, &filler));
			if ((index + 1) % 3 == 0)
				ft_printf("  ");
			if ((index + 1) % 9 == 0)
				ft_printf("\n");
			if ((index + 1) % 27 == 0)
				ft_printf("\n");
			index++;
		}
		merge_triangles(&maker, &filler);
	}
}
