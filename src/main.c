/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/02/22 21:47:26 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

int	main(void)
{
	t_push_swap_sorter	sorter;
	int					element;

	init_sorter(&sorter, 10);
	element = 0;
	while (element < 10)
	{
		enqueue(&sorter.stack_a, element);
		print_stack_info(&sorter.stack_a);
		print_stack_elements(&sorter.stack_a);
		element++;
	}
	// rotate(&sorter.stack_a);
	// print_stack_info(&sorter.stack_a);
	// print_stack_elements(&sorter.stack_a);
	// print_stacks(&sorter);
	// rotate(&sorter.stack_a);
	// print_stacks(&sorter);
	swap(&sorter.stack_a);
	print_stack_info(&sorter.stack_a);
	print_stack_elements(&sorter.stack_a);
	// print_stacks(&sorter);
	// reverse_rotate(&sorter.stack_a);
	// print_stacks(&sorter);
	// push(&sorter.stack_b, &sorter.stack_a);
	// print_stacks(&sorter);
	// push(&sorter.stack_b, &sorter.stack_a);
	// print_stacks(&sorter);
	free(sorter.stack_a.elements);
	free(sorter.stack_b.elements);
	return (EXIT_SUCCESS);
}
