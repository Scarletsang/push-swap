/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:52:46 by htsang            #+#    #+#             */
/*   Updated: 2023/03/07 20:01:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "tests/tests.h"
#include <stdio.h>

int	get_element_local_order(int index, int layer)
{
	int	order;
	int	count;

	order = index / layer;
	layer *= 3;
	count = (layer - 1) / 2;
	if (index >= count)
		order -= (1 + ((index - count) / layer));
	return (order);
}

int	get_element_order(int order, int priority)
{
	int	pow;

	if (priority == 0)
		return (order);
	pow = 1;
	while (priority > 1)
	{
		pow *= 3;
		priority--;
	}
	return (pow + order);
}

int	main(void)
{
	int	index;
	int	layer;
	int	priority;
	int	order;

	index = 0;
	while (index < 81)
	{
		layer = 1;
		priority = 4;
		printf("index: %2d: ", index);
		while ((index / layer) % 3 == 1)
		{
			priority -= 1;
			layer *= 3;
			printf("---------------");
		}
		order = get_element_local_order(index, layer);

		// printf("%d(%d)\n", priority, order - order_minus);
		printf("%d\n", get_element_order(order, priority));
		index++;
	}
	return (0);
}