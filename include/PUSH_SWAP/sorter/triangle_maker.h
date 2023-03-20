/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:27:41 by htsang            #+#    #+#             */
/*   Updated: 2023/03/20 22:12:03 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_MAKER_H
# define TRIANGLE_MAKER_H

# include "PUSH_SWAP/sorter.h"

# define EMULATION_STACK_SIZE 6

typedef t_push_swap_error_code	(*t_push_swap_formula)(\
t_push_swap_sorter *sorter, t_push_swap_triangle_maker *triangle_maker);

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
	HIGHEST_PRIORITY
}				t_push_swap_emulation_priority;

typedef struct s_push_swap_triangle_maker
{
	t_push_swap_triangle_shape				triangle_shape;
	t_push_swap_triangle_size				triangle_size;
	t_push_swap_2stacks						emulation;
	unsigned int							emulated_stack_a_rear_size;
	t_push_swap_emulation_priority_location	priority_location;
	t_push_swap_formula						last_formula_executed;
}				t_push_swap_triangle_maker;

void							set_triangle_size_and_shape(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_triangle_size triangle_size, \
t_push_swap_triangle_shape triangle_shape);

t_push_swap_error_code			init_triangle_maker(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_sorter *sorter);

///////////////////////////////////
////////     emulation     ////////
///////////////////////////////////

void							emulate_two_stacks(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_2stacks *two_stacks, \
unsigned int stackA_rear_size);

t_push_swap_emulation_priority	get_emulation_priority_by_value(\
int indexed_value, t_push_swap_triangle_maker *triangle_maker);

t_push_swap_emulation_priority	get_emulation_priority_by_index(int index, \
t_push_swap_triangle_maker *triangle_maker, t_push_swap_stack_indicator stack);

/////////////////////////////////
////////     formula     ////////
/////////////////////////////////

t_push_swap_error_code			front2(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			front1rear1(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			rear1(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			rear2(t_push_swap_sorter *sorter, \
t_push_swap_triangle_maker *triangle_maker);

////////////////////////////////////////////////
////////     push priority elements     ////////
////////////////////////////////////////////////

t_push_swap_error_code			push_priority_from_rear(\
t_push_swap_sorter *sorter, t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_emulation_priority highest_priority);

#endif