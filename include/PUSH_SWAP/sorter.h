/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/13 23:47:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "PUSH_SWAP/sorter/triangle_planner.h"

typedef enum e_push_swap_error_code
{
	SUCCESS = 0,
	FAILURE = 1
}				t_push_swap_error_code;

typedef enum e_push_swap_instruction
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}			t_push_swap_instruction;

# define EMULATION_STACK_SIZE 6

typedef enum e_push_swap_emulation_stack_rear_size
{
	RANGE_FROM_0 = 0,
	RANGE_FROM_MINUS_1 = -1,
	RANGE_FROM_MINUS_2 = -2,
	RANGE_FROM_MINUS_3 = -3
}				t_push_swap_emulation_stack_rear_size;

typedef enum e_push_swap_emulation_group
{
	SMALLEST_GROUP,
	MIDDLE_GROUP,
	BIGGEST_GROUP
}				t_push_swap_emulation_group;

typedef enum e_push_swap_triangle_size
{
	TRIANGLE_SIZE_2 = 2,
	TRIANGLE_SIZE_3 = 3,
	TRIANGLE_SIZE_4 = 4,
	TRIANGLE_SIZE_5 = 5,
	TRIANGLE_SIZE_6 = 6
}				t_push_swap_triangle_size;

typedef struct s_push_swap_instruction_list
{
	t_push_swap_instruction				instruction;
	struct s_push_swap_instruction_list	*next;
}				t_push_swap_instruction_list;

typedef struct s_push_swap_sorter
{
	t_push_swap_instruction_list			*cost;
	t_push_swap_instruction_list			*last_instruction;
	t_push_swap_instruction_list			*last_executed_instruction;
	t_push_swap_2stacks						emulation;
	t_push_swap_emulation_stack_rear_size	emulation_stack_rear_size;
}				t_push_swap_sorter;

////////////////////////////////////////////
////////     sorter manipulator     ////////
////////////////////////////////////////////

t_push_swap_error_code		add_instruction(t_push_swap_sorter *sorter, \
t_push_swap_instruction instruction);

t_push_swap_error_code		add_multiple_instructions(\
t_push_swap_sorter *sorter, t_push_swap_instruction *instruction_arr, \
unsigned int amount);

void						execute_instructions(t_push_swap_sorter *sorter, \
t_push_swap_2stacks *two_stacks, unsigned int amount);

////////////////////////////////
////////     sorter     ////////
////////////////////////////////

void						free_sorter_internals(t_push_swap_sorter *sorter);

void						increase_cost_by(t_push_swap_sorter *sorter, \
int cost);

int							get_cost(t_push_swap_sorter *sorter);

void						concat_sorter(t_push_swap_sorter *to, \
t_push_swap_sorter *from);

t_push_swap_error_code		init_sorter(t_push_swap_sorter *sorter);

//////////////////////////////////
////////     emulator     ////////
//////////////////////////////////

void						emulate_two_stacks(t_push_swap_sorter *sorter, \
t_push_swap_2stacks *two_stacks, t_push_swap_emulation_stack_rear_size from, \
t_push_swap_triangle_size triangle_size);

t_push_swap_emulation_group	get_emulation_group(int index);

////////////////////////////////////////
////////     triangle maker     ////////
////////////////////////////////////////

int							get_biggest_element_index(t_push_swap_stack *stack, \
int *indexes, unsigned int length);

t_push_swap_error_code		push_biggest_element_to_b(\
t_push_swap_sorter *sorter, t_push_swap_2stacks *two_stacks, int *indexes, \
unsigned int amount_of_indexes);

t_push_swap_error_code		sort_size_of(t_push_swap_sorter *sorter, \
t_push_swap_2stacks *two_stacks, unsigned int triangle_size);

/////////////////////////////////
////////     printer     ////////
/////////////////////////////////

void						print_instructions(t_push_swap_sorter *sorter);

#endif