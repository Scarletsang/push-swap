/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:36:17 by htsang            #+#    #+#             */
/*   Updated: 2023/02/20 23:11:31 by htsang           ###   ########.fr       */
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

int	get_free_space(t_push_swap_stack *stack)
{
	
}

void	enqueue(t_push_swap_stack *stack, int element)
{
	stack->elements[stack->size] = element; // wrong
	move_stack_bound_backwards(&stack->front, stack->size);
}

int	dequeue(t_push_swap_stack *stack)
{
	int	first_element;

	first_element = stack->elements[stack->front];
	move_stack_bound_forwards(&stack->front, stack->size);
	return (first_element);
}

void	enqueue_from_back(t_push_swap_stack *stack)
{
	
}

void	dequeue_from_back(t_push_swap_stack *stack)
{
	
}
