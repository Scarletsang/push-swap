/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:21 by htsang            #+#    #+#             */
/*   Updated: 2023/03/24 17:19:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

void	print_stack_elements(t_push_swap_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d  ", get_element_by_index(stack, i));
		i++;
	}
	ft_printf("\n");
}

void	print_stack_info(t_push_swap_stack *stack)
{
	unsigned int	i;

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

void	print_two_stacks(t_push_swap_2stacks *two_stacks)
{
	ft_printf("%-10s: ", "stack a");
	print_stack_elements(&two_stacks->stack_a);
	ft_printf("%-10s: ", "stack b");
	print_stack_elements(&two_stacks->stack_b);
	ft_printf("\n");
}
