/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 20:08:19 by htsang            #+#    #+#             */
/*   Updated: 2023/03/02 21:41:58 by htsang           ###   ########.fr       */
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

t_push_swap_triangle_shape	get_triangle_shape(unsigned int index, \
unsigned int triangle_dimension);

unsigned int				get_triangle_dimension(unsigned int stack_size);

void						print_triangle_shapes(\
unsigned int triangle_dimension);

#endif