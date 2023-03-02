/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 21:28:17 by htsang            #+#    #+#             */
/*   Updated: 2023/03/02 21:34:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

void	print_triangle_shapes(unsigned int triangle_dimension)
{
	unsigned int	index;
	unsigned int	triangles_amount;

	index = 0;
	triangles_amount = 1;
	while (index++ < triangle_dimension)
		triangles_amount *= 3;
	index = 0;
	while (index < triangles_amount)
	{
		if (get_triangle_shape(index, triangle_dimension))
			ft_printf("D");
		else
			ft_printf("A");
		if ((index + 1) % 3 == 0)
			ft_printf("  ");
		if ((index + 1) % 9 == 0)
			ft_printf("\n");
		if ((index + 1) % 27 == 0)
			ft_printf("\n");
		index++;
	}
}
