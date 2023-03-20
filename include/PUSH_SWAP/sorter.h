/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/20 22:10:56 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "PUSH_SWAP/stack.h"

typedef enum e_push_swap_error_code
{
	SUCCESS = 0,
	FAILURE = 1
}				t_push_swap_error_code;

typedef enum e_push_swap_instruction
{
	SA = -1,
	SS = -2,
	SB = -3,
	PA = 0,
	RA = 1,
	RB = 2,
	RR = 3,
	RRR = 4,
	RRB = 5,
	RRA = 6,
	PB = 7
}			t_push_swap_instruction;

typedef enum e_push_swap_triangle_size
{
	TRIANGLE_SIZE_2 = 2,
	TRIANGLE_SIZE_3 = 3,
	TRIANGLE_SIZE_4 = 4,
	TRIANGLE_SIZE_5 = 5,
	TRIANGLE_SIZE_6 = 6
}				t_push_swap_triangle_size;

typedef enum e_push_swap_triangle_shape
{
	ASCENDING_TRIANGLE,
	DESCENDING_TRIANGLE
}			t_push_swap_triangle_shape;

typedef struct s_push_swap_instruction_list
{
	t_push_swap_instruction				instruction;
	struct s_push_swap_instruction_list	*next;
}				t_push_swap_instruction_list;

typedef struct s_push_swap_sorter
{
	t_push_swap_instruction_list	*cost;
	t_push_swap_instruction_list	*last_instruction;
	t_push_swap_instruction_list	*last_executed_instruction;
	t_push_swap_2stacks				*two_stacks;
	int								automatic_execute;
}				t_push_swap_sorter;

////////////////////////////////////////////
////////     sorter manipulator     ////////
////////////////////////////////////////////

t_push_swap_error_code	add_instruction(t_push_swap_sorter *sorter, \
t_push_swap_instruction instruction);

t_push_swap_error_code	add_multiple_instructions(\
t_push_swap_sorter *sorter, t_push_swap_instruction *instruction_arr, \
unsigned int amount);

t_push_swap_error_code	add_instructions_n_times(t_push_swap_sorter *sorter, \
t_push_swap_instruction instruction, unsigned int amount);

void					edit_last_instruction(t_push_swap_sorter *sorter, \
t_push_swap_instruction instruction);

void					execute_instruction(t_push_swap_2stacks *two_stacks, \
t_push_swap_instruction instruction);

void					execute_instruction_from_sorter(\
t_push_swap_sorter *sorter, unsigned int amount);

////////////////////////////////
////////     sorter     ////////
////////////////////////////////

void					free_instruction_list(\
t_push_swap_instruction_list *instruction);

void					increase_cost_by(t_push_swap_sorter *sorter, \
int cost);

int						get_cost(t_push_swap_sorter *sorter);

void					concat_sorter(t_push_swap_sorter *to, \
t_push_swap_sorter *from);

t_push_swap_error_code	init_sorter(t_push_swap_sorter *sorter, \
t_push_swap_2stacks *two_stacks);

/////////////////////////////////
////////     printer     ////////
/////////////////////////////////

void					print_instructions(t_push_swap_sorter *sorter);

#endif