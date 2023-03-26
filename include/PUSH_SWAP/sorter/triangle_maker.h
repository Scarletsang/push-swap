/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:27:41 by htsang            #+#    #+#             */
/*   Updated: 2023/03/26 18:47:31 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_MAKER_H
# define TRIANGLE_MAKER_H

# include "PUSH_SWAP/sorter/instructor.h"
# include "PUSH_SWAP/sorter/triangle_planner.h"

# define EMULATION_STACK_SIZE 6

typedef struct s_push_swap_triangle_maker	t_push_swap_triangle_maker;

typedef t_push_swap_error_code				(*t_push_swap_formula)(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker);

typedef enum e_push_swap_triangle_size
{
	TRIANGLE_SIZE_2 = 2,
	TRIANGLE_SIZE_3 = 3,
	TRIANGLE_SIZE_4 = 4,
	TRIANGLE_SIZE_5 = 5,
	TRIANGLE_SIZE_6 = 6
}				t_push_swap_triangle_size;

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

t_push_swap_error_code			create_triangle_on_stack_a(\
t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			create_triangle_on_stack_b(\
t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

void							prepare_emulation(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_triangle_size triangle_size, \
t_push_swap_triangle_shape triangle_shape);

t_push_swap_error_code			init_triangle_maker(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker);

///////////////////////////////////
////////     emulation     ////////
///////////////////////////////////

void							emulate_two_stacks(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_2stacks *two_stacks);

t_push_swap_emulation_priority	get_emulation_priority_by_value(\
int indexed_value, t_push_swap_triangle_maker *triangle_maker);

t_push_swap_emulation_priority	get_emulation_priority_by_index(int index, \
t_push_swap_triangle_maker *triangle_maker);

/////////////////////////////////////////
////////     stack_b formula     ////////
/////////////////////////////////////////

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

/////////////////////////////////////////
////////     stack_a formula     ////////
/////////////////////////////////////////

typedef enum e_push_swap_size4_formula_hash
{
	HASH_0123 = 12,
	HASH_1023 = 11,
	HASH_2130 = 3,
	HASH_2031 = -3,
	HASH_3201 = -7,
	HASH_3210 = 0
}				t_push_swap_size4_formula_hash;

typedef enum e_push_swap_size4_formula_indicator
{
	STARTS_WITH_0 = 0,
	STARTS_WITH_1,
	STARTS_WITH_2,
	STARTS_WITH_3,
}				t_push_swap_size4_formula_indicator;

t_push_swap_error_code			size2(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			size3(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			size4(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			size5_or_6(t_push_swap_instructor *instructor, \
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
t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker, unsigned int priority_amount);

#endif