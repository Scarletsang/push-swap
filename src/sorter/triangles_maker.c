/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:50:53 by htsang            #+#    #+#             */
/*   Updated: 2023/03/05 20:48:52 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

// void	create_(unsigned int stack_size)
// {
// 	unsigned int				index;
// 	t_push_swap_triangles_maker	maker;

// 	init_triangles_maker(&maker, stack_size);
// 	index = 0;
// 	while (index < maker.largest_triangles_amount)
// 	{
// 		if (get_triangle_shape(index, maker.largest_triangles_amount))
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

void	merge_triangles(t_push_swap_triangles_maker *maker, \
unsigned int stack_size)
{
	maker->mininum_triangle_size *= 3;
	maker->triangles_size_delta *= 3;
	maker->largest_triangles_amount /= 3;
	maker->remainder = stack_size - (maker->mininum_triangle_size * \
		maker->largest_triangles_amount);
}

void	init_triangles_maker(t_push_swap_triangles_maker *maker, \
unsigned int stack_size)
{
	maker->mininum_triangle_size = 2;
	maker->triangles_size_delta = 4;
	maker->largest_triangles_amount = get_largest_triangles_amount(\
		stack_size);
	maker->remainder = stack_size - (maker->mininum_triangle_size * \
		maker->largest_triangles_amount);
}
