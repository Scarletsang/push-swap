/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulated_instruction_executor.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:58:36 by htsang            #+#    #+#             */
/*   Updated: 2023/03/21 23:34:28 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

static void	update_emulation_stack_front_and_rear_size(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instruction instruction)
{
	if (instruction == RA)
	{
		triangle_maker->emulated_stack_a_front_size--;
		triangle_maker->emulated_stack_a_rear_size++;
	}
	else if (instruction == RRA)
	{
		triangle_maker->emulated_stack_a_front_size++;
		triangle_maker->emulated_stack_a_rear_size--;
	}
	else if (instruction == PB)
	{
		triangle_maker->emulated_stack_a_front_size--;
	}
}

t_push_swap_error_code	emulate_instruction(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instruction instruction)
{
	triangle_maker->last_formula_executed = NULL;
	update_emulation_stack_front_and_rear_size(triangle_maker, \
		instruction);
	return (add_instruction(instructor, instruction));
}

t_push_swap_error_code	emulate_formula_instructions(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instruction *instruction_arr)
{
	unsigned int	i;

	i = 1;
	while (i < (unsigned int) instruction_arr[0])
	{
		emulate_instruction(instructor, triangle_maker, instruction_arr[i]);
		i++;
	}
	return (SUCCESS);
}

t_push_swap_error_code	emulate_multiple_instructions(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instruction *instruction_arr)
{
	triangle_maker->last_formula_executed = NULL;
	return (emulate_formula_instructions(instructor, triangle_maker, \
		instruction_arr));
}

void	edit_last_emulated_instruction(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instruction instruction)
{
	update_emulation_stack_front_and_rear_size(triangle_maker, \
			get_inverse_instruction(\
				instructor->last_executed_instruction->instruction));
	update_emulation_stack_front_and_rear_size(triangle_maker, \
			instruction);
	edit_last_instruction(instructor, instruction);
}
