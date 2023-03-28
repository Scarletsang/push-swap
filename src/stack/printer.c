/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:33:21 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:01:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"
#include "FT_PRINTF/ft_printf.h"

void	stack_print_elements(t_push_swap_stack *stack)
{
	unsigned int	i;

	i = 0;
	while (i < stack->size)
	{
		ft_printf("%d  ", stack_get_element_by_index(stack, i));
		i++;
	}
	ft_printf("\n");
}

void	stack_print_info(t_push_swap_stack *stack)
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

void	two_stacks_print(t_push_swap_2stacks *two_stacks)
{
	ft_printf("%-10s: ", "stack a");
	stack_print_elements(&two_stacks->stack_a);
	ft_printf("%-10s: ", "stack b");
	stack_print_elements(&two_stacks->stack_b);
	ft_printf("\n");
}
