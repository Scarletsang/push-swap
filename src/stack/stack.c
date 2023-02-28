/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:36:17 by htsang            #+#    #+#             */
/*   Updated: 2023/02/28 00:23:57 by htsang           ###   ########.fr       */
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

int	get_element_by_index(t_push_swap_stack *stack, int index)
{
	if (index < 0)
	{
		return (stack->elements[(stack->rear + stack->max_size + \
			(index % stack->max_size)) % stack->max_size]);
	}
	return (stack->elements[(stack->front + index) % stack->max_size]);
}

void	init_stack_from_array(t_push_swap_stack *stack, size_t elements_size, \
int *elements)
{
	stack->max_size = elements_size;
	stack->elements = elements;
	stack->size = elements_size;
	stack->front = 0;
	stack->rear = elements_size - 1;
}

int	init_empty_stack(t_push_swap_stack *stack, size_t max_stack_size)
{
	stack->max_size = max_stack_size;
	stack->elements = malloc(sizeof(int) * max_stack_size);
	if (!stack->elements)
	{
		return (EXIT_FAILURE);
	}
	stack->size = 0;
	stack->front = 0;
	stack->rear = 0;
	return (EXIT_SUCCESS);
}
