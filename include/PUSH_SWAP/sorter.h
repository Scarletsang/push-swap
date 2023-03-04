/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/03 23:52:42 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORTER_H
# define SORTER_H

# include "PUSH_SWAP/stack.h"
# include <unistd.h>

typedef enum e_push_swap_triangle_shape
{
	ASCENDING_TRIANGLE,
	DESCENDING_TRIANGLE
}	t_push_swap_triangle_shape;

typedef struct s_push_swap_triangles_maker
{
	unsigned int	triangle_base_size;
	unsigned int	largest_triangles_amount;
	unsigned int	remainder;
	unsigned int	mid_index;
}	t_push_swap_triangles_maker;

t_push_swap_triangle_shape	get_triangle_shape(unsigned int index, \
unsigned int largest_triangles_amount);

unsigned int				get_largest_triangles_amount(\
unsigned int stack_size);

unsigned int				get_triangle_size(unsigned int index, \
t_push_swap_triangles_maker *triangles);

void						merge_triangles(\
t_push_swap_triangles_maker *maker, unsigned int stack_size);

void						init_triangles_maker(\
t_push_swap_triangles_maker *triangles, unsigned int stack_size);

void						print_triangle_shapes(\
unsigned int stack_size);

#endif