/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:16:10 by htsang            #+#    #+#             */
/*   Updated: 2023/02/23 22:38:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

int	init_sorter(t_push_swap_sorter *sorter, size_t elements_size, \
int *stack_a_elements)
{
	init_stack_from_array(&sorter->stack_a, elements_size, stack_a_elements);
	if (init_empty_stack(&sorter->stack_b, elements_size))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
