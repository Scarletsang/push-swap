/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_planner.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 19:27:41 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 06:00:20 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_PLANNER_H
# define TRIANGLE_PLANNER_H

# include "PUSH_SWAP/sorter/instructor.h"

//////////////////////////////////////////////
////////     The triangle planner     ////////
//////////////////////////////////////////////

/**
 * @brief Triangle planner store all the triangle sizes and states needed to
 * calculate the shape of each triangle.
 * 
 * All Triangles' size are precalculated and stored in an array called
 * triangles_size. The size of the array is total_triangles. 
 * 
 * Merge_dimension is the number of times merge needs to happen in order
 * to merge all triangles into one single sorted big triangle.
 */
typedef struct s_push_swap_triangles_planner
{
	unsigned int		*triangles_size;
	const unsigned int	total_elements;
	unsigned int		total_triangles;
	const unsigned int	merge_dimension;
	unsigned int		mininum_triangle_size;
	unsigned int		triangles_size_delta;
}				t_push_swap_triangles_planner;

int							triangles_planner_init(\
t_push_swap_triangles_planner *maker, unsigned int total_elements);

void						triangles_planner_merge(\
t_push_swap_triangles_planner *maker);

/////////////////////////////////////////////////////////////
////////     triangle planner's internal getters     ////////
/////////////////////////////////////////////////////////////

unsigned int				triangles_planner_get_total_triangles(\
unsigned int total_elements);

unsigned int				triangles_planner_get_merge_dimension(\
unsigned int total_triangles);

unsigned int				\
triangles_plannerget_important_triangles_before_index(\
unsigned int triangle_index, unsigned int layer);

///////////////////////////////////////////////////////
////////     Calculate triangles_size size     ////////
///////////////////////////////////////////////////////

typedef enum e_push_swap_triangle_fill_mode
{
	FILL_ALL_EVENLY,
	FILL_IMPORTANT_FIRST,
	FILL_UNIMPORTANT_EVENLY
}			t_push_swap_triangle_fill_mode;

typedef struct s_push_swap_triangles_size_calculator
{
	unsigned int					total_important_triangles;
	t_push_swap_triangle_fill_mode	fill_mode;
	unsigned int					target_triangle_size;
	unsigned int					first_partially_filled_triangle;
}				t_push_swap_triangles_size_calculator;

int							triangles_size_calculator_init(\
t_push_swap_triangles_size_calculator *calculator, \
t_push_swap_triangles_planner *planner);

void						triangles_planner_calculate_triangles_sizes(\
t_push_swap_triangles_planner *maker);

//////////////////////////////////////////////////
////////     Calculate triangle shape     ////////
//////////////////////////////////////////////////

/**
 * @brief The sorted elements on stack_b can either be ascending or
 * descending. This is the type to represents this distinction. The type
 * is implemented as a function pointer, so that not only one can use
 * the function pointer address to represents the triangle shape, one can
 * also run the function to make comparision between the value of the
 * elements.
 */
typedef int					(*t_push_swap_triangle_shape)(int element_a, \
int element_b);

int							triangle_shape_ascending(int element_a, \
int element_b);

int							triangle_shape_descending(int element_a, \
int element_b);

t_push_swap_triangle_shape	triangle_shape_switch(\
t_push_swap_triangle_shape triangle_shape);

t_push_swap_triangle_shape	triangles_planner_calculate_triangle_shape(\
unsigned int triangle_index, unsigned int total_triangles, \
const unsigned int merge_dimension);

/////////////////////////////////////////////////////////
////////     Triangles size and shape printer    ////////
/////////////////////////////////////////////////////////

void						triangles_planner_print(\
t_push_swap_triangles_planner *planner);

#endif