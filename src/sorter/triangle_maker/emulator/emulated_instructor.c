/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulated_instructor.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 19:58:36 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 07:38:08 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker/emulator.h"

static void	emulator_update_stack_front_and_rear_size(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instruction instruction)
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

t_push_swap_error_code	emulated_instructor_add(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction)
{
	triangle_maker->last_formula_executed = NULL;
	emulator_update_stack_front_and_rear_size(triangle_maker, \
		instruction);
	return (instructor_add(instructor, instruction));
}

t_push_swap_error_code	emulated_instructor_add_formula(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
t_push_swap_instruction *instruction_arr)
{
	unsigned int	i;

	i = 0;
	while (i < (unsigned int) instruction_arr[0])
	{
		emulator_update_stack_front_and_rear_size(triangle_maker, \
			instruction_arr[i + 1]);
		if (instructor_add(instructor, instruction_arr[i + 1]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

t_push_swap_error_code	emulated_instructor_add_multiple(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
t_push_swap_instruction *instruction_arr)
{
	triangle_maker->last_formula_executed = NULL;
	return (emulated_instructor_add_formula(triangle_maker, instructor, \
		instruction_arr));
}

void	emulated_instructor_edit_last(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction)
{
	emulator_update_stack_front_and_rear_size(triangle_maker, \
			instruction_get_inverse(\
				instructor->last_executed_instruction->instruction));
	emulator_update_stack_front_and_rear_size(triangle_maker, \
			instruction);
	instructor_edit_last(instructor, instruction);
}
