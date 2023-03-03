/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:28:17 by htsang            #+#    #+#             */
/*   Updated: 2023/03/03 03:54:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

void	print_triangle_shapes(unsigned int stack_size)
{
	unsigned int				index;
	t_push_swap_triangles_maker	maker;

	init_triangles_maker(&maker, stack_size);
	index = 0;
	while (index < maker.largest_triangles_amount)
	{
		if (get_triangle_shape(index, maker.largest_triangles_amount))
			ft_printf("D");
		else
			ft_printf("A");
		ft_printf("(%u) ", get_triangle_size(index, &maker));
		if ((index + 1) % 3 == 0)
			ft_printf("  ");
		if ((index + 1) % 9 == 0)
			ft_printf("\n");
		if ((index + 1) % 27 == 0)
			ft_printf("\n");
		index++;
	}
}
