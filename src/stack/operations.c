/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:09:01 by htsang            #+#    #+#             */
/*   Updated: 2023/03/26 15:34:06 by htsang           ###   ########.fr       */
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
	first_element = dequeue_from_front(stack);
	second_element = dequeue_from_front(stack);
	enqueue(stack, first_element);
	enqueue(stack, second_element);
	return (EXIT_SUCCESS);
}

int	push(t_push_swap_stack *dest, t_push_swap_stack *src)
{
	if (src->size == 0)
	{
		return (EXIT_SUCCESS);
	}
	enqueue(dest, dequeue_from_front(src));
	return (EXIT_SUCCESS);
}

int	rotate(t_push_swap_stack *stack)
{
	if (stack->size < 2)
	{
		return (EXIT_SUCCESS);
	}
	enqueue_to_back(stack, dequeue_from_front(stack));
	return (EXIT_SUCCESS);
}

int	reverse_rotate(t_push_swap_stack *stack)
{
	if (stack->size < 2)
	{
		return (EXIT_SUCCESS);
	}
	enqueue(stack, dequeue(stack));
	return (EXIT_SUCCESS);
}
