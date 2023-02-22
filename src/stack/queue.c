/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:57:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/22 21:43:57 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

void	enqueue(t_push_swap_stack *stack, int element)
{
	if (stack->size > 0)
	{
		move_stack_bound_backwards(&stack->front, stack->max_size);
	}
	stack->elements[stack->front] = element;
	stack->size++;
}

void	enqueue_to_back(t_push_swap_stack *stack, int element)
{
	if (stack->size > 0)
	{
		move_stack_bound_forwards(&stack->rear, stack->max_size);
	}
	stack->elements[stack->rear] = element;
	stack->size++;
}

int	dequeue(t_push_swap_stack *stack)
{
	int	first_element;

	first_element = stack->elements[stack->front];
	if (stack->size > 1)
	{
		move_stack_bound_forwards(&stack->front, stack->max_size);
	}
	stack->size--;
	return (first_element);
}

int	dequeue_from_back(t_push_swap_stack *stack)
{
	int	last_element;

	last_element = stack->elements[stack->rear];
	if (stack->size > 1)
	{
		move_stack_bound_backwards(&stack->rear, stack->max_size);
	}
	stack->size--;
	return (last_element);
}
