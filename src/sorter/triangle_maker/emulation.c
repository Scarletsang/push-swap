/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:02:07 by htsang            #+#    #+#             */
/*   Updated: 2023/03/21 21:11:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

static void	index_element(t_push_swap_triangle_maker *triangle_maker, \
int indexed_stack[EMULATION_STACK_SIZE], t_push_swap_stack_bound index)
{
	unsigned int			i;
	int						current;

	current = triangle_maker->emulation.stack_a.elements[index];
	i = 0;
	indexed_stack[index] = 0;
	if (triangle_maker->triangle_shape == ASCENDING_TRIANGLE)
	{
		while (i < triangle_maker->emulation.stack_a.size)
		{
			if (current < get_element_by_index(\
				&triangle_maker->emulation.stack_a, i++))
				indexed_stack[index]++;
		}
		return ;
	}
	while (i < triangle_maker->emulation.stack_a.size)
	{
		if (current > get_element_by_index(\
			&triangle_maker->emulation.stack_a, i++))
			indexed_stack[index]++;
	}
}

static void	index_emulation_stack_a(t_push_swap_triangle_maker *triangle_maker)
{
	t_push_swap_stack_bound	front;
	unsigned int			i;
	int						indexed_stack[EMULATION_STACK_SIZE];

	front = triangle_maker->emulation.stack_a.front;
	while (front != triangle_maker->emulation.stack_a.rear)
	{
		index_element(triangle_maker, indexed_stack, front);
		move_stack_bound_forwards(&front, EMULATION_STACK_SIZE);
	}
	index_element(triangle_maker, indexed_stack, front);
	i = 0;
	while (i < EMULATION_STACK_SIZE)
	{
		triangle_maker->emulation.stack_a.elements[i] = indexed_stack[i];
		i++;
	}
}

t_push_swap_emulation_priority	get_emulation_priority_by_value(\
int indexed_value, t_push_swap_triangle_maker *triangle_maker)
{
	if (((triangle_maker->triangle_size % 2) == 1) && \
		(triangle_maker->triangle_shape == ASCENDING_TRIANGLE))
	{
		return ((indexed_value + 1) / 2);
	}
	return (indexed_value / 2);
}

t_push_swap_emulation_priority	get_emulation_priority_by_index(int index, \
t_push_swap_triangle_maker *triangle_maker, t_push_swap_stack_indicator stack)
{
	if (stack == STACK_A)
		return (get_emulation_priority_by_value(\
			get_element_by_index(&triangle_maker->emulation.stack_a, \
				index), triangle_maker));
	return (get_emulation_priority_by_value(\
		get_element_by_index(&triangle_maker->emulation.stack_b, \
			index), triangle_maker));
}

void	emulate_two_stacks(t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_2stacks *two_stacks)
{
	unsigned int	stack_a_rear_size;
	unsigned int	stack_a_front_size;

	stack_a_rear_size = triangle_maker->emulated_stack_a_rear_size;
	while (stack_a_rear_size > 0)
	{
		enqueue_to_back(&triangle_maker->emulation.stack_a, \
			get_element_by_index(&two_stacks->stack_a, \
				stack_a_rear_size * -1));
		stack_a_rear_size--;
	}
	stack_a_front_size = triangle_maker->emulated_stack_a_front_size;
	while (stack_a_front_size > 0)
	{
		enqueue(&triangle_maker->emulation.stack_a, \
			get_element_by_index(&two_stacks->stack_a, \
				stack_a_front_size * -1));
		stack_a_front_size--;
	}
	index_emulation_stack_a(triangle_maker);
}
