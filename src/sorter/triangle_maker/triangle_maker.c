/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:09:35 by htsang            #+#    #+#             */
/*   Updated: 2023/03/20 22:08:27 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

void	set_triangle_size_and_shape(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_triangle_size triangle_size, \
t_push_swap_triangle_shape triangle_shape)
{
	triangle_maker->triangle_size = triangle_size;
	triangle_maker->triangle_shape = triangle_shape;
}

t_push_swap_error_code	init_triangle_maker(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_sorter *sorter)
{
	if (init_empty_stack(&triangle_maker->emulation.stack_a, \
		EMULATION_STACK_SIZE) || \
		init_empty_stack(&triangle_maker->emulation.stack_b, \
		EMULATION_STACK_SIZE) || \
		init_sorter(sorter, &triangle_maker->emulation))
		return (FAILURE);
	triangle_maker->priority_location = UNKNOWN_PRIORITY_LOCATION;
	sorter->automatic_execute = 1;
	return (SUCCESS);
}
