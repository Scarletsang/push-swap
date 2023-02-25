/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:30:33 by htsang            #+#    #+#             */
/*   Updated: 2023/02/26 00:37:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>
# include "FT_PRINTF/ft_printf.h"

/////////////////////////////////////////
////////     stack interface     ////////
/////////////////////////////////////////

typedef size_t	t_push_swap_stack_bound;

typedef struct s_push_swap_stack
{
	int						*elements;
	t_push_swap_stack_bound	front;
	t_push_swap_stack_bound	rear;
	size_t					max_size;
	size_t					size;
}				t_push_swap_stack;

void	init_stack_from_array(t_push_swap_stack *stack, size_t max_stack_size, \
int *elements);

int		init_empty_stack(t_push_swap_stack *stack, size_t max_stack_size);

void	move_stack_bound_forwards(t_push_swap_stack_bound *bound, \
size_t	max_stack_size);

void	move_stack_bound_backwards(t_push_swap_stack_bound *bound, \
size_t	max_stack_size);

int		get_front_element(t_push_swap_stack *stack);

////////////////////////////////////
////////     two stacks     ////////
////////////////////////////////////

typedef struct s_push_swap_2stacks
{
	t_push_swap_stack	stack_a;
	t_push_swap_stack	stack_b;
}				t_push_swap_2stacks;

int		init_two_stacks(t_push_swap_2stacks *two_stacks, size_t elements_size, \
int *stack_a_elements);

void	print_two_stacks(t_push_swap_2stacks *sorter);

/////////////////////////////////////////
////////     Queue interface     ////////
/////////////////////////////////////////

void	enqueue(t_push_swap_stack *stack, int element);

void	enqueue_to_back(t_push_swap_stack *stack, int element);

int		dequeue(t_push_swap_stack *stack);

int		dequeue_from_back(t_push_swap_stack *stack);

/////////////////////////////////////////
////////     Core operations     ////////
/////////////////////////////////////////

int		swap(t_push_swap_stack *stack);

int		push(t_push_swap_stack *dest, t_push_swap_stack *src);

int		rotate(t_push_swap_stack *stack);

int		reverse_rotate(t_push_swap_stack *stack);

/////////////////////////////////
////////     Printer     ////////
/////////////////////////////////

void	print_stack_elements(t_push_swap_stack *stack);

void	print_stack_info(t_push_swap_stack *stack);

void	print_two_stacks(t_push_swap_2stacks *two_stacks);

#endif