/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_planner.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:27:41 by htsang            #+#    #+#             */
/*   Updated: 2023/03/23 18:12:59 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_PLANNER_H
# define TRIANGLE_PLANNER_H

# include "PUSH_SWAP/sorter/instructor.h"

typedef enum e_push_swap_triangle_fill_mode
{
	FILL_ALL_EVENLY,
	FILL_IMPORTANT_FIRST,
	FILL_UNIMPORTANT_EVENLY
}			t_push_swap_triangle_fill_mode;

typedef struct s_push_swap_triangles_calculator
{
	unsigned int					total_important_triangles;
	t_push_swap_triangle_fill_mode	fill_mode;
	unsigned int					target_triangle_size;
	unsigned int					first_partially_filled_triangle;
}				t_push_swap_triangles_calculator;

typedef struct s_push_swap_triangles_planner
{
	unsigned int		*triangles;
	const unsigned int	total_elements;
	unsigned int		total_triangles;
	const unsigned int	triangle_dimension;
	unsigned int		mininum_triangle_size;
	unsigned int		triangles_size_delta;
}				t_push_swap_triangles_planner;

unsigned int				get_total_triangles(\
unsigned int total_elements);

unsigned int				get_triangle_dimension(\
unsigned int total_triangles);

unsigned int				get_important_triangles_before(\
unsigned int triangle_index, unsigned int layer);

int							init_triangles_planner(\
t_push_swap_triangles_planner *maker, unsigned int total_elements);

int							init_triangles_filler(\
t_push_swap_triangles_planner *maker, t_push_swap_triangles_calculator *filler);

void						precalculate_all_triangles_size(\
t_push_swap_triangles_planner *maker);

void						merge_triangles_planner(\
t_push_swap_triangles_planner *maker);

t_push_swap_triangle_shape	get_triangle_shape(\
unsigned int triangle_index, unsigned int total_triangles);

int							print_all_triangles_merge(\
unsigned int total_elements);

void						print_triangles(\
t_push_swap_triangles_planner *planner);

#endif