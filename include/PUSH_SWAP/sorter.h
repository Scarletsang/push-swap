/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/08 12:49:47 by htsang           ###   ########.fr       */
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
}			t_push_swap_triangle_shape;

typedef enum e_push_swap_triangle_fill_mode
{
	FILL_ALL_EVENLY,
	FILL_IMPORTANT_FIRST,
	FILL_UNIMPORTANT_EVENLY
}			t_push_swap_triangle_fill_mode;

typedef struct s_push_swap_triangles_filler
{
	unsigned int					total_important_triangles;
	t_push_swap_triangle_fill_mode	fill_mode;
	unsigned int					triangle_dimension;
	unsigned int					target_triangle_size;
	unsigned int					first_partially_filled_triangle;
}				t_push_swap_triangles_filler;

typedef struct s_push_swap_triangles_maker
{
	const unsigned int	total_elements;
	unsigned int		total_triangles;
	unsigned int		mininum_triangle_size;
	unsigned int		triangles_size_delta;
}				t_push_swap_triangles_maker;

unsigned int				get_total_triangles(\
unsigned int total_elements);

unsigned int	            get_triangle_dimension(\
unsigned int total_triangles);

unsigned int				get_important_triangles_before(\
unsigned int triangle_index, unsigned int layer);

void						merge_triangles(\
t_push_swap_triangles_maker *maker, t_push_swap_triangles_filler *filler);

void						init_triangles_maker(\
t_push_swap_triangles_maker *triangles, t_push_swap_triangles_filler *filler, \
unsigned int total_elements);

t_push_swap_triangle_shape	get_triangle_shape(\
unsigned int triangle_index, unsigned int total_triangles);

unsigned int				get_triangle_order(unsigned int triangle_index, \
unsigned int dimension);

unsigned int				get_triangle_size(unsigned int triangle_index, \
t_push_swap_triangles_maker *maker, t_push_swap_triangles_filler *filler);

void						print_triangle_shapes(\
unsigned int total_elements);

#endif