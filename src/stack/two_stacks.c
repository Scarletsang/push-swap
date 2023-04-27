/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_stacks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:16:10 by htsang            #+#    #+#             */
/*   Updated: 2023/04/27 15:18:45 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

int	two_stacks_is_sorted(t_push_swap_2stacks *two_stacks)
{
	int				last_element_value;
	int				current_element_value;
	unsigned int	i;

	if (two_stacks->stack_b.size != 0)
	{
		return (0);
	}
	i = 0;
	last_element_value = stack_get_element_by_index(&two_stacks->stack_a, i);
	while (++i < two_stacks->stack_a.size)
	{
		current_element_value = stack_get_element_by_index(\
			&two_stacks->stack_a, i);
		if (last_element_value > current_element_value)
		{
			return (0);
		}
		last_element_value = current_element_value;
	}
	return (1);
}

void	two_stacks_free(t_push_swap_2stacks *two_stacks)
{
	if (two_stacks->stack_a.elements)
		free(two_stacks->stack_a.elements);
	if (two_stacks->stack_b.elements)
		free(two_stacks->stack_b.elements);
}

int	two_stacks_init(t_push_swap_2stacks *two_stacks, \
unsigned int elements_size, int *stack_a_elements)
{
	stack_init_from_array(&two_stacks->stack_a, elements_size, \
		stack_a_elements);
	if (stack_init_empty(&two_stacks->stack_b, elements_size))
	{
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
