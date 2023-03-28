/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   emulator.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 07:34:54 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 08:31:09 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EMULATOR_H
# define EMULATOR_H

# include "PUSH_SWAP/sorter/instructor.h"
# include "PUSH_SWAP/sorter/triangle_maker.h"

////////////////////////////////////////////
////////     Emulator interface     ////////
////////////////////////////////////////////

t_push_swap_emulation_priority	emulator_get_priority_of_value(\
t_push_swap_triangle_maker *triangle_maker, int indexed_value);

t_push_swap_emulation_priority	emulator_get_priority_of_index(\
t_push_swap_triangle_maker *triangle_maker, int index);

//////////////////////////////////////////////////////////////
////////     Emulated instructor action interface     ////////
//////////////////////////////////////////////////////////////

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
////////     stack_b formula     ////////
/////////////////////////////////////////

/**
 * Formula generates sequence of instructions that sorts a certain number of
 * elements that are each located in a specific place. Stack_b formula sorts
 * elements from stack_a to stack_b.
*/

t_push_swap_error_code			emulator_formula_front2(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			emulator_formula_front1rear1(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			emulator_formula_rear1(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			emulator_formula_last2(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

t_push_swap_error_code			emulator_formula_last1(\
t_push_swap_triangle_maker *triangle_maker, t_push_swap_instructor *instructor);

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