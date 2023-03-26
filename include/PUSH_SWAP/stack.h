/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:30:33 by htsang            #+#    #+#             */
/*   Updated: 2023/03/26 16:10:58 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

/////////////////////////////////////////
////////     Stack interface     ////////
/////////////////////////////////////////

/**
 * @brief A stack bound is the index of the stack front/rear element in the
 * element array. This type signifies the bound of the stack. This type can be
 * used in combination with @ref move_stack_bound_forwards() or
 * move_stack_bounds_backwards() to iterate and mutate values on the stack.
 * However if one wants to iterate the stack without mutating the stack, use 
 * @ref get_element_by_index() instead.
 */
typedef unsigned int	t_push_swap_stack_bound;

/**
 * @brief A stack where rotation within the stack is allowed. It is implemented
 * using circular array. Elements are stored in an array, the front and rear is
 * conceptually two pointers pointing to the location of the front and rear 
 * element of the stack. Max size is the maximum number of elements the stack
 * can hold. Size is the current number of elements in the stack.
 */
typedef struct s_push_swap_stack
{
	int						*elements;
	t_push_swap_stack_bound	front;
	t_push_swap_stack_bound	rear;
	unsigned int			max_size;
	unsigned int			size;
}				t_push_swap_stack;

void	init_stack_from_array(t_push_swap_stack *stack, \
unsigned int max_stack_size, int *elements);

int		init_empty_stack(t_push_swap_stack *stack, unsigned int max_stack_size);

void	move_stack_bound_forwards(t_push_swap_stack_bound *bound, \
unsigned int max_stack_size);

void	move_stack_bound_backwards(t_push_swap_stack_bound *bound, \
unsigned int max_stack_size);

/**
 * @brief Gets the element at the specified index relative to the stack front or
 * rear.
 * @param stack A stack
 * @param index the index of the element relative to the stack front or rear.
 * Index 0 is the stack front, index -1 is the stack rear.
 * @return the queried element
 */
int		get_element_by_index(t_push_swap_stack *stack, int index);

/////////////////////////////////////////
////////     Queue interface     ////////
/////////////////////////////////////////

/**
 * Normally a stack offers at least the push() and pop() operation. However,
 * since the stack in push_swap allows rotation, it is easier to implement
 * the core operations using a queue interface. It has the normal enqueue()
 * and dequeue() operations, but also the offbeat enqueue_to_back() and 
 * dequeue_from_front() to encompass the need of the core operations.
*/

void	enqueue(t_push_swap_stack *stack, int element);

void	enqueue_to_back(t_push_swap_stack *stack, int element);

int		dequeue_from_front(t_push_swap_stack *stack);

int		dequeue(t_push_swap_stack *stack);

/////////////////////////////////////////
////////     Core operations     ////////
/////////////////////////////////////////

int		swap(t_push_swap_stack *stack);

int		push(t_push_swap_stack *dest, t_push_swap_stack *src);

int		rotate(t_push_swap_stack *stack);

int		reverse_rotate(t_push_swap_stack *stack);

////////////////////////////////////////
////////     The two stacks     ////////
////////////////////////////////////////

/**
 * @brief A holder of 2 stacks. Not only for the convinience of passing 2
 * stacks around, but also there must be 2 and only 2 stacks for the core
 * operations to work.
 */
typedef struct s_push_swap_2stacks
{
	t_push_swap_stack	stack_a;
	t_push_swap_stack	stack_b;
}				t_push_swap_2stacks;

int		init_two_stacks(t_push_swap_2stacks *two_stacks, \
unsigned int elements_size, int *stack_a_elements);

void	free_two_stacks(t_push_swap_2stacks *two_stacks);

//////////////////////////////////////////
////////     Stack(s) Printer     ////////
//////////////////////////////////////////

void	print_two_stacks(t_push_swap_2stacks *sorter);

void	print_stack_elements(t_push_swap_stack *stack);

void	print_stack_info(t_push_swap_stack *stack);

void	print_two_stacks(t_push_swap_2stacks *two_stacks);

#endif