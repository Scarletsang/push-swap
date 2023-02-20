/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 21:30:33 by htsang            #+#    #+#             */
/*   Updated: 2023/02/20 22:58:44 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef	size_t	t_push_swap_stack_bound;

typedef struct s_push_swap_stack
{
    int						*elements;
    t_push_swap_stack_bound	front;
    t_push_swap_stack_bound	rear;
    size_t					size;
}               t_push_swap_stack;

#endif