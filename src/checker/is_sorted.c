/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 23:21:33 by htsang            #+#    #+#             */
/*   Updated: 2023/02/27 22:51:47 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/checker.h"

int	is_sorted(t_push_swap_2stacks *two_stacks)
{
	int		last_element_value;
	int		current_element_value;
	size_t	i;

	if (two_stacks->stack_b.size != 0)
	{
		return (0);
	}
	i = 0;
	last_element_value = get_element_by_index(&two_stacks->stack_a, i);
	while (++i < two_stacks->stack_a.size)
	{
		current_element_value = get_element_by_index(&two_stacks->stack_a, i);
		if (last_element_value > current_element_value)
		{
			return (0);
		}
		last_element_value = current_element_value;
	}
	return (1);
}
