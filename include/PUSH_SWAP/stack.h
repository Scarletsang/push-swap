/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:30:33 by htsang            #+#    #+#             */
/*   Updated: 2023/02/21 12:54:51 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef size_t	t_push_swap_stack_bound;

typedef struct s_push_swap_stack
{
	int						*elements;
	t_push_swap_stack_bound	front;
	t_push_swap_stack_bound	rear;
	size_t					max_size;
	size_t					size;
}				t_push_swap_stack;

int		init_stack(t_push_swap_stack *stack, size_t stack_size);

void	move_stack_bound_forwards(t_push_swap_stack_bound *bound, \
size_t	max_stack_size);

void	move_stack_bound_backwards(t_push_swap_stack_bound *bound, \
size_t	max_stack_size);

int		get_front_element(t_push_swap_stack *stack);

int		get_rear_element(t_push_swap_stack *stack);

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

void	swap(t_push_swap_stack *stack);

void	push(t_push_swap_stack *dest, t_push_swap_stack *src);

void	rotate(t_push_swap_stack *stack);

void	reverse_rotate(t_push_swap_stack *stack);

/////////////////////////////////
////////     Printer     ////////
/////////////////////////////////

int		ft_printf(const char *str, ...);

void	print_stack_elements(t_push_swap_stack *stack);

void	print_stack_info(t_push_swap_stack *stack);

#endif