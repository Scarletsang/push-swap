/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:09:01 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:06:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

int	swap(t_push_swap_stack *stack)
{
	int	first_element;
	int	second_element;

	if (stack->size < 2)
	{
		return (EXIT_SUCCESS);
	}
	first_element = stack_dequeue_from_front(stack);
	second_element = stack_dequeue_from_front(stack);
	stack_enqueue(stack, first_element);
	stack_enqueue(stack, second_element);
	return (EXIT_SUCCESS);
}

int	push(t_push_swap_stack *dest, t_push_swap_stack *src)
{
	if (src->size == 0)
	{
		return (EXIT_SUCCESS);
	}
	stack_enqueue(dest, stack_dequeue_from_front(src));
	return (EXIT_SUCCESS);
}

int	rotate(t_push_swap_stack *stack)
{
	if (stack->size < 2)
	{
		return (EXIT_SUCCESS);
	}
	stack_enqueue_to_back(stack, stack_dequeue_from_front(stack));
	return (EXIT_SUCCESS);
}

int	reverse_rotate(t_push_swap_stack *stack)
{
	if (stack->size < 2)
	{
		return (EXIT_SUCCESS);
	}
	stack_enqueue(stack, stack_dequeue(stack));
	return (EXIT_SUCCESS);
}
