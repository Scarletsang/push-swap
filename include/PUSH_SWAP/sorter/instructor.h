/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructor.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/26 18:41:30 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INSTRUCTOR_H
# define INSTRUCTOR_H

# include "PUSH_SWAP/stack.h"

/**
 * @brief This type encapsulate the possibility that the function can fail.
 * Since element in the stack has the type of int, this type avoid confusion by
 * distingushing failure of malloc() and the value of a stack element.
 * Furthermore, when a function returns this type, it means the function might
 * add instruction to the instructor, thus having the possibility to fail
 * during malloc(). In other words, a function with this return type might adds
 * instruction, while one that does not is only responsible for computation.
 */
typedef enum e_push_swap_error_code
{
	SUCCESS = 0,
	FAILURE = 1
}				t_push_swap_error_code;

/**
 * @brief Enum representing all valid instructions. The value of each enum is
 * carefully designed to ease the proccess of undoing instructions or optimizing
 * instructions. See @ref get_inverse_instruction() for more details. Also see
 * the optimizer module that utilizes the value of each enum.
 */
typedef enum e_push_swap_instruction
{
	SA = -1,
	SS = -2,
	SB = -3,
	PA = 0,
	RA = 1,
	RR = 2,
	RB = 3,
	RRB = 4,
	RRR = 5,
	RRA = 6,
	PB = 7
}			t_push_swap_instruction;

/**
 * @brief Returns the inverse instruction of the given instruction. For example,
 * PA is the inverse of PB, RA is that of RRA, etc. However, the swap instructions
 * are their own inverse, i.e. SA is the inverse of SA, SS is the inverse of SS.
 * Therfore, the enum of the swap instructions are made negative, so that it can
 * be programmatically distingushed from the other instructions.
 * @param instruction the instruction to be inverted
 * @return the inverted instruction
 */
t_push_swap_instruction	get_inverse_instruction(\
t_push_swap_instruction instruction);

///////////////////////////////////////////////////
////////     instruction list interface    ////////
///////////////////////////////////////////////////

typedef struct s_push_swap_instruction_list
{
	t_push_swap_instruction				instruction;
	struct s_push_swap_instruction_list	*next;
}				t_push_swap_instruction_list;

void					free_instruction_list(\
t_push_swap_instruction_list *instruction);

/////////////////////////////////////////////
////////     instructor interface    ////////
/////////////////////////////////////////////

/**
 * @brief Instructor not only holds the start and end of one instruction list,
 * it is also capable of executing the instruction list on the two stacks. The
 * start of the instruction list always store the total length of the linked list,
 * which represents how costly does the instruction list is.
 * 
 * For the convinience of the triangle maker, the instructor always need to 
 * execute the instruction immediately after it has been added to the list,
 * an option to automatically execute instruction is provided. When that option
 * is disabled, the instruction list will only executes on demand. Therefore,
 * there is one extra pointer pointing to the last executed instruction.
 */
typedef struct s_push_swap_instructor
{
	t_push_swap_instruction_list	*cost;
	t_push_swap_instruction_list	*last_instruction;
	t_push_swap_instruction_list	*last_executed_instruction;
	t_push_swap_2stacks				*two_stacks;
	int								automatic_execute;
}				t_push_swap_instructor;

void					increase_cost_by(t_push_swap_instructor *instructor, \
int cost);

int						get_cost(t_push_swap_instructor *instructor);

void					concat_instructor(t_push_swap_instructor *to, \
t_push_swap_instructor *from);

t_push_swap_error_code	init_instructor(t_push_swap_instructor *instructor, \
t_push_swap_2stacks *two_stacks);

/////////////////////////////////////////////////////
////////     instructor action interface     ////////
/////////////////////////////////////////////////////

/**
 * Instructor, as previously mentioned, is capable of add instructions, and
 * execute them on the two stacks. The following functions are the interface.
*/

t_push_swap_error_code	add_instruction(t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction);

t_push_swap_error_code	add_multiple_instructions(\
t_push_swap_instructor *instructor, \
t_push_swap_instruction *instruction_arr);

t_push_swap_error_code	add_instructions_n_times(\
t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction, unsigned int n);

void					edit_last_instruction(\
t_push_swap_instructor *instructor, t_push_swap_instruction instruction);

void					execute_instruction(t_push_swap_2stacks *two_stacks, \
t_push_swap_instruction instruction);

void					execute_unexecuted_instructions(\
t_push_swap_instructor *instructor);

/////////////////////////////////////////////
////////     Instruction printer     ////////
/////////////////////////////////////////////

void					print_instructions(t_push_swap_instructor *instructor);

#endif