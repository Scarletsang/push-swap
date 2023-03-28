/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_maker.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:27:41 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 07:09:24 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_MAKER_H
# define TRIANGLE_MAKER_H

# include "PUSH_SWAP/sorter/instructor.h"
# include "PUSH_SWAP/sorter/triangle_planner.h"

# define EMULATION_STACK_SIZE 6

/**
 * @brief The triangle maker generate instructions that consider the
 * top 2-6 elements of stack_a, and sort them into stack_b or stack_a.
 * Triangle_size determines the number of elements that will be sorted.
 * Triangle_shape determines if the elements will be sorted in ascending or
 * descending order.
 * 
 * Implementation-wise, the triangle maker has its own two stacks, that
 * emulate the behavior of the top 2-6 elements from stack_a. Those 2-6
 * elements will be indexed, thus a seperated two stacks is needed to
 * keep the original values of the elements in the original two stacks.
 * 
 * Emulation is achieved by copying 2-6 elements from the original two
 * stacks to the emulated two stacks which can only holds up to 6 elements
 * each. To compromise the absent of the rest of the elements in the
 * original two stacks, the triangle maker stores the number of elements
 * present in front and rear of the emulated stack_a so that the triangle
 * maker keeps track of how many the emulating elements are at the front
 * and the rear of stack_a respectively. This is what the
 * "emulated_stack_a_rear_size" and "emulated_stack_a_front_size" fields
 * are for.
 * 
 * To ease the process of comparing the values of those elements during
 * sorting, the values are mapped to a range of 0 to 5. This kind of indexing
 * is executed when the function @ref triangle_maker_emulate_two_stacks is
 * called. To comprehend sorting both in ascending and descending order,
 * instead of thinking about indexing as just mapping down the values to an
 * easiest range of number to process, triangle maker indexed the values
 * according to which element has a higher priority to be sorted first.
 * Higher the priority index, meaning that that element should be pushed to
 * its desired location prior to the other elements.
 * 
 * The sorting algorithm sorts items in groups of two. The two highest
 * priority elements are first sorted, then the next two, so on. And
 * therefore the type @ref t_push_swap_emulation_priority does not refer to
 * the priority index, but the priority group of two elements. 
 */
typedef struct s_push_swap_triangle_maker	t_push_swap_triangle_maker;

//////////////////////////////////////////////////////////////
////////     Triangle maker's emulation interface     ////////
//////////////////////////////////////////////////////////////

typedef enum e_push_swap_emulation_priority
{
	LOWEST_PRIORITY,
	MEDIUM_PRIORITY,
	HIGHEST_PRIORITY,
	UNKNOWN_PRIORITY
}				t_push_swap_emulation_priority;

void							triangle_maker_emulate_two_stacks(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_2stacks *two_stacks);

t_push_swap_emulation_priority	emulator_get_priority_by_value(\
t_push_swap_triangle_maker *triangle_maker, int indexed_value);

t_push_swap_emulation_priority	emulator_get_priority_by_index(\
t_push_swap_triangle_maker *triangle_maker, int index);

//////////////////////////////////////////////////////////////////////
////////     Triangle maker's instructor action interface     ////////
//////////////////////////////////////////////////////////////////////

/**
 * A wrapper of the original instructor action interface. In the context of
 * triangle maker, adding and executing instructions always needs to
 * be complimented with an action to update the emulated_stack_a_rear_size
 * and emulated_stack_a_front_size field in the triangle_maker struct. This is
 * why this interface is necessary.
*/

t_push_swap_error_code			emulated_instructor_add(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction);

t_push_swap_error_code			emulated_instructor_add_formula(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
t_push_swap_instruction *instruction_arr);

t_push_swap_error_code			emulated_instructor_add_multiple(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
t_push_swap_instruction *instruction_arr);

void							emulated_instructor_edit_last(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
t_push_swap_instruction instruction);

/////////////////////////////////////////
////////     stack_a formula     ////////
/////////////////////////////////////////

/**
 * Formula generates sequence of instructions that sorts a certain number of
 * elements that are each located in a specific place. Stack_a formula sorts
 * elements on stack_a, with a limited use of stack_b.
*/

/**
 * @brief There are 6 basic forms that 4 elements can be ordered such that
 * the instructions generated are very different. Each form is associated with
 * an optimal sequence of instructions that sorts such form. To determine which
 * form the current sequence is, the triangle maker hashes the current sequence.
 */
typedef enum e_push_swap_size4_formula_hash
{
	HASH_0123 = 12,
	HASH_1023 = 11,
	HASH_2130 = 3,
	HASH_2031 = -3,
	HASH_3201 = -7,
	HASH_3210 = 0
}				t_push_swap_size4_formula_hash;

/**
 * @brief Once the hash of the current sequence is determined, the triangle maker
 * need to rotate/reverse rotate the elements on stack_a so that the current
 * sequence becomes one of the 6 basic ordering. Each basic ordering starts with
 * a different index. Therefore, triangle maker can simply rotate the current
 * sequence until the front of stack_a is of the index as the determined basic
 * ordering. This type is used during such rotation.
 */
typedef enum e_push_swap_size4_formula_start
{
	STARTS_WITH_0 = 0,
	STARTS_WITH_1,
	STARTS_WITH_2,
	STARTS_WITH_3,
}				t_push_swap_size4_formula_start;

typedef t_push_swap_error_code				(*t_push_swap_formula)(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			triangle_maker_formula_size2(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			triangle_maker_formula_size3(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			triangle_maker_formula_size4(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			triangle_maker_formula_size5_or_6(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

/////////////////////////////////////////
////////     stack_b formula     ////////
/////////////////////////////////////////

/**
 * Formula generates sequence of instructions that sorts a certain number of
 * elements that are each located in a specific place. Stack_b formula sorts
 * elements from stack_a to stack_b.
*/

t_push_swap_error_code			triangle_maker_formula_front2(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			triangle_maker_formula_front1rear1(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			triangle_maker_formula_rear1(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			triangle_maker_formula_last2(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			triangle_maker_formula_last1(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

/////////////////////////////////////////
//////    The triangle maker    /////////
/////////////////////////////////////////

/**
 * @brief A triangle is simply a locally sorted elements on a stack. This
 * type represents all the possible size of a triangle.
 */
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

struct s_push_swap_triangle_maker
{
	const t_push_swap_triangle_shape		triangle_shape;
	const t_push_swap_triangle_size			triangle_size;
	t_push_swap_2stacks						emulation;
	unsigned int							emulated_stack_a_rear_size;
	unsigned int							emulated_stack_a_front_size;
	t_push_swap_emulation_priority_location	priority_location;
	t_push_swap_emulation_priority			highest_priority;
	t_push_swap_formula						last_formula_executed;
};

t_push_swap_error_code			triangle_maker_init(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker);

t_push_swap_error_code			triangle_maker_create_triangle_on_stack_a(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instructor *instructor);

t_push_swap_error_code			triangle_maker_create_triangle_on_stack_b(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_instructor *instructor);

/**
 * @brief Reset all triangle_maker's states to emulate a new set of elements.
 * It is therefore used before @ref triangle_maker_emulate_two_stacks().
 * @param triangle_maker the triangle maker
 * @param triangle_size the number of elements to sort
 * @param triangle_shape sort the elements in ascending or descending order
 * in stack_b
 */
void							triangle_maker_update(\
t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_triangle_size triangle_size, \
t_push_swap_triangle_shape triangle_shape);

////////////////////////////////////////
////////     Priority mover     ////////
////////////////////////////////////////

/**
 * @brief The central algorithm to create triangles from stack_a to stack_b.
 * It first checks the front and rear of stack_a, if there is at least one
 * priority element in either position, then push it to stack_b. Otherwise,
 * it will search through stack_a from front to find a priority element. If
 * the priority element is located at n elements away from front, it will
 * do (n - 2) times of ra. Then it left the priority element at the second
 * place, which is index 1. Next, the algorithm will determine whether the
 * element at index 0 should be displaced by ra or sa. For the implementation
 * of this part, please check the function
 * @ref emulator_is_priority_decrease_after_sa(). Let's rewind a bit, what if
 * there is no priority at the front of stack_a? Then the priroity element must
 * locate in the rear, the algorithm just need to simply rra until the priority
 * is at the rear, and it can be pushed to stack_b by simplying applying
 * rra pb.
 * 
 * @param instructor the instructor to add instructions to
 * @param triangle_maker the triangle maker
 * @param priority_amount number of priority elements to sort
 * @return @ref t_push_swap_error_code
 */
t_push_swap_error_code			emulator_move_priority_elements(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor, \
unsigned int priority_amount);

#endif