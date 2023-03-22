/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 22:14:16 by htsang            #+#    #+#             */
/*   Updated: 2023/03/22 03:53:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/instructor.h"

void	print_instruction(t_push_swap_instruction instruction)
{
	if (instruction == SA)
		ft_printf("sa");
	else if (instruction == SB)
		ft_printf("sb");
	else if (instruction == SS)
		ft_printf("ss");
	else if (instruction == PA)
		ft_printf("pa");
	else if (instruction == PB)
		ft_printf("pb");
	else if (instruction == RA)
		ft_printf("ra");
	else if (instruction == RB)
		ft_printf("rb");
	else if (instruction == RR)
		ft_printf("rr");
	else if (instruction == RRA)
		ft_printf("rra");
	else if (instruction == RRB)
		ft_printf("rrb");
	else if (instruction == RRR)
		ft_printf("rrr");
}

void	print_instructions(t_push_swap_instructor *instructor)
{
	t_push_swap_instruction_list	*instructions;

	instructions = instructor->cost->next;
	while (instructions)
	{
		print_instruction(instructions->instruction);
		ft_printf("\n");
		instructions = instructions->next;
	}
}
