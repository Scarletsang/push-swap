/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:16:10 by htsang            #+#    #+#             */
/*   Updated: 2023/02/21 13:18:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

int	init_sorter(t_push_swap_sorter *sorter, size_t elements_size)
{
	if (init_stack(&sorter->stack_a, elements_size + 1))
	{
		return (EXIT_FAILURE);
	}
	if (init_stack(&sorter->stack_b, elements_size + 1))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
