/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:02:07 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 07:14:41 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

static void	triangle_maker_index_element(\
t_push_swap_triangle_maker *triangle_maker, \
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

static void	triangle_maker_index_emulated_stack_a(\
t_push_swap_triangle_maker *triangle_maker)
{
	t_push_swap_stack_bound	front;
	unsigned int			i;
	int						indexed_stack[EMULATION_STACK_SIZE];

	front = triangle_maker->emulation.stack_a.front;
	while (front != triangle_maker->emulation.stack_a.rear)
	{
		triangle_maker_index_element(triangle_maker, indexed_stack, front);
		stack_bound_move_forwards(&front, EMULATION_STACK_SIZE);
	}
	triangle_maker_index_element(triangle_maker, indexed_stack, front);
	i = 0;
	while (i < EMULATION_STACK_SIZE)
	{
		triangle_maker->emulation.stack_a.elements[i] = indexed_stack[i];
		i++;
	}
}

void	triangle_maker_emulate_two_stacks(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_2stacks *two_stacks)
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
	triangle_maker_index_emulated_stack_a(triangle_maker);
}
