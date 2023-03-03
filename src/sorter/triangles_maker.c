/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangles_maker.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 03:50:53 by htsang            #+#    #+#             */
/*   Updated: 2023/03/03 03:52:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

void	init_triangles_maker(t_push_swap_triangles_maker *triangles, \
unsigned int stack_size)
{
	triangles->largest_triangles_amount = get_largest_triangles_amount(\
		stack_size);
	triangles->triangle_base_size = stack_size / \
		triangles->largest_triangles_amount;
	triangles->remainder = stack_size % triangles->largest_triangles_amount;
	triangles->mid_index = (triangles->largest_triangles_amount - 1) / 2;
}
