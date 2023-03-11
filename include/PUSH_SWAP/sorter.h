/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/11 23:17:11 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "PUSH_SWAP/sorter/triangle_planner.h"

typedef enum e_push_swap_error_code
{
	SUCCESS = 0,
	MALLOC_FAILS = 1
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
}				t_push_swap_sorter;

t_push_swap_error_code	add_instruction(t_push_swap_sorter *sorter, \
t_push_swap_instruction instruction);

t_push_swap_error_code	add_multiple_instructions(t_push_swap_sorter *sorter, \
t_push_swap_instruction *instruction_arr, unsigned int amount);

void					execute_instructions(t_push_swap_sorter *sorter, \
t_push_swap_2stacks *two_stacks, unsigned int amount);

void					clean_sorter(t_push_swap_sorter *sorter);

void					increase_cost_by(t_push_swap_sorter *sorter, \
int cost);

int						get_cost(t_push_swap_sorter *sorter);

t_push_swap_error_code	init_sorter(t_push_swap_sorter *sorter);

void					concat_sorter(t_push_swap_sorter *to, \
t_push_swap_sorter *from);

int						get_biggest_element_index(t_push_swap_stack *stack, \
int *indexes, unsigned int length);

t_push_swap_error_code	push_biggest_element_to_b(\
t_push_swap_sorter *sorter, t_push_swap_2stacks *two_stacks, int *indexes, \
unsigned int amount_of_indexes);

t_push_swap_error_code	sort_size_of(t_push_swap_sorter *sorter, \
t_push_swap_2stacks *two_stacks, unsigned int triangle_size);

void					print_instructions(t_push_swap_sorter *sorter);

#endif