/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:09:01 by htsang            #+#    #+#             */
/*   Updated: 2023/02/21 11:28:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

void	swap(t_push_swap_stack *stack)
{
	int	first_element;
	int	second_element;

	if (stack->max_size < 2)
	{
		return ;
	}
	first_element = dequeue(stack);
	second_element = dequeue(stack);
	enqueue(stack, first_element);
	enqueue(stack, second_element);
}

void	push(t_push_swap_stack *dest, t_push_swap_stack *src)
{
	if (src->size == 0)
	{
		return ;
	}
	enqueue(dest, dequeue(src));
}

void	rotate(t_push_swap_stack *stack)
{
	if (stack->max_size < 2)
	{
		return ;
	}
	enqueue_to_back(stack, dequeue(stack));
}

void	reverse_rotate(t_push_swap_stack *stack)
{
	if (stack->max_size < 2)
	{
		return ;
	}
	enqueue(stack, dequeue_from_back(stack));
}
