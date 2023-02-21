/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 13:19:35 by htsang            #+#    #+#             */
/*   Updated: 2023/02/21 13:21:40 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter.h"

void	print_stacks(t_push_swap_sorter *sorter)
{
	ft_printf("%-10s: ", "stack a");
	print_stack_elements(&sorter->stack_a);
	ft_printf("%-10s: ", "stack b");
	print_stack_elements(&sorter->stack_b);
}
