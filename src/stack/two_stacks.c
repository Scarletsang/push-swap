/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:16:10 by htsang            #+#    #+#             */
/*   Updated: 2023/03/02 21:46:15 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

int	init_two_stacks(t_push_swap_2stacks *two_stacks, \
unsigned int elements_size, int *stack_a_elements)
{
	init_stack_from_array(&two_stacks->stack_a, elements_size, \
		stack_a_elements);
	if (init_empty_stack(&two_stacks->stack_b, elements_size))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
