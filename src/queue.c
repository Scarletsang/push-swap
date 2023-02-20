/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 23:57:19 by htsang            #+#    #+#             */
/*   Updated: 2023/02/20 23:57:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

void	enqueue(t_push_swap_stack *stack, int element)
{
	move_stack_bound_backwards(&stack->front, stack->size);
	stack->elements[stack->front] = element;
}

void	enqueue_from_back(t_push_swap_stack *stack, int element)
{
	move_stack_bound_forwards(&stack->rear, stack->size);
	stack->elements[stack->rear] = element;
}

int	dequeue(t_push_swap_stack *stack)
{
	int	first_element;

	first_element = stack->elements[stack->front];
	move_stack_bound_forwards(&stack->front, stack->size);
	return (first_element);
}

int	dequeue_from_back(t_push_swap_stack *stack)
{
	int	last_element;

	last_element = stack->elements[stack->rear];
	move_stack_bound_backwards(&stack->rear, stack->size);
	return (last_element);	
}
