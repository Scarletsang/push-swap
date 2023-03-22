/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:27:41 by htsang            #+#    #+#             */
/*   Updated: 2023/03/21 23:40:00 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_MAKER_H
# define TRIANGLE_MAKER_H

# include "PUSH_SWAP/sorter/instructor.h"

# define EMULATION_STACK_SIZE 6

typedef struct s_push_swap_triangle_maker t_push_swap_triangle_maker;

typedef t_push_swap_error_code	(*t_push_swap_formula)(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker);

typedef enum e_push_swap_stack_indicator
{
	STACK_A,
	STACK_B
}				t_push_swap_stack_indicator;

typedef enum e_push_swap_emulation_priority_location
{
	UNKNOWN_PRIORITY_LOCATION,
	PRIORITY_AT_FRONT,
	PRIORITY_AT_REAR
}				t_push_swap_emulation_priority_location;

typedef enum e_push_swap_emulation_priority
{
	LOWEST_PRIORITY,
	MEDIUM_PRIORITY,
	HIGHEST_PRIORITY,
	UNKNOWN_PRIORITY
}				t_push_swap_emulation_priority;

struct s_push_swap_triangle_maker
{
	t_push_swap_triangle_shape				triangle_shape;
	t_push_swap_triangle_size				triangle_size;
	t_push_swap_2stacks						emulation;
	unsigned int							emulated_stack_a_rear_size;
	unsigned int							emulated_stack_a_front_size;
	t_push_swap_emulation_priority_location	priority_location;
	t_push_swap_emulation_priority			highest_priority;
	t_push_swap_formula						last_formula_executed;
};

t_push_swap_error_code			create_triangle(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

void							prepare_emulation(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_triangle_size triangle_size, \
t_push_swap_triangle_shape triangle_shape);

t_push_swap_error_code			init_triangle_maker(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

///////////////////////////////////
////////     emulation     ////////
///////////////////////////////////

void							emulate_two_stacks(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_2stacks *two_stacks);

t_push_swap_emulation_priority	get_emulation_priority_by_value(\
int indexed_value, t_push_swap_triangle_maker *triangle_maker);

t_push_swap_emulation_priority	get_emulation_priority_by_index(int index, \
t_push_swap_triangle_maker *triangle_maker, t_push_swap_stack_indicator stack);

/////////////////////////////////
////////     formula     ////////
/////////////////////////////////

t_push_swap_error_code			front2(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			front1rear1(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			rear1(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			last2(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			last1(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

////////////////////////////////////////////////
////////     push priority elements     ////////
////////////////////////////////////////////////

t_push_swap_error_code			emulate_instruction(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instruction instruction);

t_push_swap_error_code			emulate_formula_instructions(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instruction *instruction_arr);

t_push_swap_error_code			emulate_multiple_instructions(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instruction *instruction_arr);

void							edit_last_emulated_instruction(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instruction instruction);

t_push_swap_error_code			move_priority_elements(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker, \
unsigned int priority_amount, \
t_push_swap_emulation_priority_location forced_search);

#endif