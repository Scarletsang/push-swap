/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:21:33 by htsang            #+#    #+#             */
/*   Updated: 2023/02/25 23:33:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/checker.h"

int	is_sorted(t_push_swap_2stacks *two_stacks)
{
	int	last_element_value;
	int	current_element_value;
	int	front;

	if (two_stacks->stack_b.size != 0)
	{
		return (0);
	}
	front = two_stacks->stack_a.front;
	last_element_value = get_front_element(&two_stacks->stack_a);
	while (two_stacks->stack_a.front != two_stacks->stack_a.rear)
	{
		move_stack_bound_forwards(&two_stacks->stack_a.front, \
			two_stacks->stack_a.max_size);
		current_element_value = get_front_element(&two_stacks->stack_a);
		if (last_element_value > current_element_value)
		{
			return (0);
		}
		last_element_value = current_element_value;
	}
	two_stacks->stack_a.front = front;
	return (1);
}
