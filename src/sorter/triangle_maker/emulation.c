/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:02:07 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 04:59:28 by htsang           ###   ########.fr       */
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
	while (i < triangle_maker->emulation.stack_a.size)
	{
		if (triangle_maker->triangle_shape(stack_get_element_by_index(\
			&triangle_maker->emulation.stack_a, i++), current))
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
		stack_bound_move_forwards(&front, EMULATION_STACK_SIZE);
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
	if ((triangle_maker->triangle_size % 2) == 1)
	{
		return ((indexed_value + 1) / 2);
	}
	return (indexed_value / 2);
}

t_push_swap_emulation_priority	get_emulation_priority_by_index(int index, \
t_push_swap_triangle_maker *triangle_maker)
{
	if ((index < 0) && \
		(-index > (int) triangle_maker->emulated_stack_a_rear_size))
		return (UNKNOWN_PRIORITY);
	if ((index >= 0) && \
		(index >= (int) triangle_maker->emulated_stack_a_front_size))
		return (UNKNOWN_PRIORITY);
	return (get_emulation_priority_by_value(\
		stack_get_element_by_index(&triangle_maker->emulation.stack_a, \
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
		stack_enqueue_to_back(&triangle_maker->emulation.stack_a, \
			stack_get_element_by_index(&two_stacks->stack_a, \
				stack_a_rear_size * -1));
		stack_a_rear_size--;
	}
	stack_a_front_size = triangle_maker->emulated_stack_a_front_size;
	while (stack_a_front_size > 0)
	{
		stack_enqueue(&triangle_maker->emulation.stack_a, \
			stack_get_element_by_index(&two_stacks->stack_a, \
				stack_a_front_size - 1));
		stack_a_front_size--;
	}
	index_emulation_stack_a(triangle_maker);
}
