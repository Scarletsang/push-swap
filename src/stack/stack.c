/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:36:17 by htsang            #+#    #+#             */
/*   Updated: 2023/02/21 12:43:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

void	move_stack_bound_forwards(t_push_swap_stack_bound *bound, \
size_t	max_stack_size)
{
	if ((*bound + 1) == max_stack_size)
	{
		*bound = 0;
	}
	else
	{
		(*bound)++;
	}
}

void	move_stack_bound_backwards(t_push_swap_stack_bound *bound, \
size_t	max_stack_size)
{
	if (*bound == 0)
	{
		*bound = max_stack_size - 1;
	}
	else
	{
		(*bound)--;
	}
}

int	get_front_element(t_push_swap_stack *stack)
{
	return (stack->elements[stack->front]);
}

int	get_rear_element(t_push_swap_stack *stack)
{
	return (stack->elements[stack->rear]);
}

int	init_stack(t_push_swap_stack *stack, size_t max_stack_size)
{
	stack->max_size = max_stack_size + 1;
	stack->elements = malloc(sizeof(int) * stack->max_size);
	if (!stack->elements)
	{
		return (EXIT_FAILURE);
	}
	stack->size = 0;
	stack->front = 0;
	stack->rear = 0;
	return (EXIT_SUCCESS);
}
