/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:21 by htsang            #+#    #+#             */
/*   Updated: 2023/02/21 12:52:18 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

void	print_stack_elements(t_push_swap_stack *stack)
{
	int	front;

	front = stack->front;
	while (stack->front != stack->rear)
	{
		ft_printf("%d  ", get_front_element(stack));
		move_stack_bound_forwards(&stack->front, stack->max_size);
	}
	ft_printf("%d\n", get_front_element(stack));
	stack->front = front;
}

void	print_stack_info(t_push_swap_stack *stack)
{
	size_t	i;

	ft_printf("%-10s: %d\n", "front", stack->front);
	ft_printf("%-10s: %d\n", "rear", stack->rear);
	ft_printf("%-10s: %d\n", "size", stack->size);
	ft_printf("%-10s: %d\n", "max-size", stack->max_size);
	ft_printf("%-10s: ", "elements");
	i = 0;
	while (i < stack->max_size)
	{
		ft_printf("%d  ", stack->elements[i]);
		i++;
	}
	ft_printf("\n");
}
