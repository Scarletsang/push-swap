/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:29:34 by htsang            #+#    #+#             */
/*   Updated: 2023/02/21 12:50:39 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/stack.h"

int	main(void)
{
	t_push_swap_stack	stack;
	int					element;

	init_stack(&stack, 10);
	element = 0;
	while (element < 10)
	{
		enqueue(&stack, element);
		element++;
	}
	print_stack_elements(&stack);
	rotate(&stack);
	print_stack_elements(&stack);
	rotate(&stack);
	print_stack_elements(&stack);
	swap(&stack);
	print_stack_elements(&stack);
	reverse_rotate(&stack);
	print_stack_elements(&stack);
	free(stack.elements);
	return (EXIT_SUCCESS);
}
