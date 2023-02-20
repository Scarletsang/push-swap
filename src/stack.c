/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:36:17 by htsang            #+#    #+#             */
/*   Updated: 2023/02/21 00:01:25 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

void	move_stack_bound_forwards(t_push_swap_stack_bound *bound, \
size_t	stack_size)
{
	if (*bound == (stack_size - 1))
	{
		*bound = 0;
	}
	else
	{
		(*bound)++;
	}
}

void	move_stack_bound_backwards(t_push_swap_stack_bound *bound, \
size_t	stack_size)
{
	if (*bound == 0)
	{
		*bound = stack_size;
	}
	else
	{
		(*bound)--;
	}
}

int	init_stack(t_push_swap_stack *stack, size_t stack_size)
{
	stack->size = stack_size + 1;
	stack->elements = malloc(sizeof(int) * stack->size);
	if (!stack->elements)
	{
		return (EXIT_FAILURE);
	}
	stack->front = 0;
	stack->rear = stack_size;
	return (EXIT_SUCCESS);
}
