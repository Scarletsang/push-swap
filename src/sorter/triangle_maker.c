/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:34:18 by htsang            #+#    #+#             */
/*   Updated: 2023/03/13 20:29:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

int	get_biggest_element_index(t_push_swap_stack *stack, int *indexes, \
unsigned int amount_of_instructions)
{
	int		biggest_element;
	int		current_element;
	int		biggest_index;

	biggest_index = *indexes;
	biggest_element = get_element_by_index(stack, biggest_index);
	indexes++;
	while (amount_of_instructions > 1)
	{
		current_element = get_element_by_index(stack, *indexes);
		if (current_element > biggest_element)
		{
			biggest_element = current_element;
			biggest_index = *indexes;
		}
		amount_of_instructions--;
		indexes++;
	}
	return (biggest_index);
}

t_push_swap_error_code	add_and_execute_instructions(\
t_push_swap_sorter *sorter, t_push_swap_2stacks *two_stacks, \
t_push_swap_instruction *instructions, unsigned int amount_of_instructions)
{
	if (add_multiple_instructions(sorter, instructions, \
		amount_of_instructions))
		return (FAILURE);
	execute_instructions(sorter, two_stacks, amount_of_instructions);
	return (SUCCESS);
}

t_push_swap_error_code	push_biggest_element_to_b(\
t_push_swap_sorter *sorter, t_push_swap_2stacks *two_stacks, int *indexes, \
unsigned int amount_of_indexes)
{
	int	biggest_element_index;

	biggest_element_index = get_biggest_element_index(&two_stacks->stack_a, \
		indexes, amount_of_indexes);
	if (biggest_element_index == 0)
	{
		return (add_and_execute_instructions(sorter, two_stacks, \
			(t_push_swap_instruction[1]){PB}, 1));
	}
	if (biggest_element_index == 1)
	{
		return (add_and_execute_instructions(sorter, two_stacks, \
			(t_push_swap_instruction[2]){SA, PB}, 2));
	}
	if (biggest_element_index == 2)
	{
		return (add_and_execute_instructions(sorter, two_stacks, \
			(t_push_swap_instruction[4]){RA, SA, PB, RRA}, 4));
	}
	return (SUCCESS);
}

t_push_swap_error_code	sort_size_of(t_push_swap_sorter *sorter, \
t_push_swap_2stacks *two_stacks, unsigned int triangle_size)
{
	while (triangle_size > 0)
	{
		if (push_biggest_element_to_b(sorter, two_stacks, \
			(int [6]){0, 1, 2, 3, 4, 5}, triangle_size))
			return (FAILURE);
		triangle_size--;
	}
	return (SUCCESS);
}
