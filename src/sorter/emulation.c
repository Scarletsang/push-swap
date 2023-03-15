/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:02:07 by htsang            #+#    #+#             */
/*   Updated: 2023/03/15 09:08:21 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

static void	index_element(t_push_swap_sorter *sorter, int *indexed_stack, \
t_push_swap_stack_bound index)
{
	unsigned int			i;
	int						current;

	current = sorter->emulation.stack_a.elements[index];
	i = 0;
	indexed_stack[index] = 0;
	while (i < sorter->emulation.stack_a.size)
	{
		if (current > get_element_by_index(&sorter->emulation.stack_a, i++))
			indexed_stack[index]++;
	}
}

static void	index_emulation_stack_a(t_push_swap_sorter *sorter)
{
	t_push_swap_stack_bound	front;
	unsigned int			i;
	int						indexed_stack[EMULATION_STACK_SIZE];

	front = sorter->emulation.stack_a.front;
	while (front != sorter->emulation.stack_a.rear)
	{
		index_element(sorter, indexed_stack, front);
		move_stack_bound_forwards(&front, EMULATION_STACK_SIZE);
	}
	index_element(sorter, indexed_stack, front);
	i = 0;
	while (i < EMULATION_STACK_SIZE)
	{
		sorter->emulation.stack_a.elements[i] = indexed_stack[i];
		i++;
	}
}

t_push_swap_emulation_group	get_emulation_group(int index, \
t_push_swap_triangle_size triangle_size, t_push_swap_triangle_shape shape)
{
	if (((triangle_size % 2) == 1) && (shape == ASCENDING_TRIANGLE))
	{
		return ((index + 1) / 2);
	}
	return (index / 2);
}

void	emulate_two_stacks(t_push_swap_sorter *sorter, \
t_push_swap_2stacks *two_stacks, t_push_swap_emulation_range_from from, \
t_push_swap_triangle_size triangle_size)
{
	int	to;

	sorter->emulation.stack_a.size = 0;
	sorter->emulation.stack_a.front = 0;
	sorter->emulation.stack_a.rear = 0;
	sorter->emulation.stack_b.size = 0;
	sorter->emulation.stack_b.front = 0;
	sorter->emulation.stack_b.rear = 0;
	sorter->emulation_range_from = from;
	to = from + triangle_size - 1;
	while (from < 0)
	{
		enqueue_to_back(&sorter->emulation.stack_a, \
			get_element_by_index(&two_stacks->stack_a, from));
		from++;
	}
	while (to >= from)
	{
		enqueue(&sorter->emulation.stack_a, \
			get_element_by_index(&two_stacks->stack_a, to));
		to--;
	}
	index_emulation_stack_a(sorter);
}
