/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formula_size4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 10:05:38 by htsang            #+#    #+#             */
/*   Updated: 2023/03/23 16:21:07 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/sorter/triangle_maker.h"

static t_push_swap_size4_formula_hash	hash_size4_triangle(\
t_push_swap_triangle_maker *triangle_maker)
{
	t_push_swap_size4_formula_hash	hash;
	unsigned int					i;
	int								current;
	int								next;

	i = 0;
	current = get_element_by_index(&triangle_maker->emulation.stack_a, i) - \
		(triangle_maker->triangle_size - TRIANGLE_SIZE_4);
	hash = 0;
	while (i < 4)
	{
		next = get_element_by_index(&triangle_maker->emulation.stack_a, \
			(i + 1) % 4) - (triangle_maker->triangle_size - TRIANGLE_SIZE_4);
		if (current == 2)
			hash += ((current - 6) * (current - next));
		else
			hash += (current * (current - next));
		current = next;
		i++;
	}
	return (hash);
}

static t_push_swap_size4_formula_indicator	get_indicator_from_hash(\
t_push_swap_size4_formula_hash hash, t_push_swap_triangle_size triangle_size)
{
	if (hash == HASH_0123)
		return (STARTS_WITH_0 + (triangle_size - TRIANGLE_SIZE_4));
	if (hash == HASH_1023)
		return (STARTS_WITH_1 + (triangle_size - TRIANGLE_SIZE_4));
	if (((hash % 3) == 0) && (hash != 0))
		return (STARTS_WITH_2 + (triangle_size - TRIANGLE_SIZE_4));
	return (STARTS_WITH_3 + (triangle_size - TRIANGLE_SIZE_4));
}

static t_push_swap_error_code	size4_from_hash(\
t_push_swap_instructor *instructor, t_push_swap_size4_formula_hash hash)
{
	if (hash == HASH_0123)
		return (SUCCESS);
	if (hash == HASH_1023)
		return (add_instruction(instructor, SA));
	if (hash == HASH_2130)
		return (add_multiple_instructions(instructor, \
			(t_push_swap_instruction[3]){2, SA, RRA}));
	if (hash == HASH_2031)
		return (add_multiple_instructions(instructor, \
			(t_push_swap_instruction[4]){3, SA, RRA, SA}));
	if (hash == HASH_3201)
		return (add_multiple_instructions(instructor, \
			(t_push_swap_instruction[4]){3, SA, RRA, RRA}));
	return (add_multiple_instructions(instructor, \
		(t_push_swap_instruction[5]){4, SA, RRA, RRA, SA}));
}

static t_push_swap_error_code	rotate_to_get_to_size4_formula(\
t_push_swap_instructor *instructor, t_push_swap_triangle_maker *triangle_maker, \
t_push_swap_size4_formula_hash hash)
{
	t_push_swap_size4_formula_indicator	indicator;
	unsigned int						indicator_location;

	indicator = get_indicator_from_hash(hash, triangle_maker->triangle_size);
	indicator_location = 0;
	while ((indicator_location < 4) && ((unsigned int) get_element_by_index(\
		&triangle_maker->emulation.stack_a, indicator_location) != indicator))
		indicator_location++;
	if (indicator_location == 3)
	{
		if (add_instruction(instructor, RRA))
			return (FAILURE);
	}
	else if (indicator_location == 2)
	{
		if (add_multiple_instructions(instructor, \
			(t_push_swap_instruction[3]){2, RA, RA}))
			return (FAILURE);
	}
	else if (indicator_location == 1)
	{
		if (add_instruction(instructor, RA))
			return (FAILURE);
	}
	return (SUCCESS);
}

t_push_swap_error_code	size4(t_push_swap_instructor *instructor, \
t_push_swap_triangle_maker *triangle_maker)
{
	t_push_swap_size4_formula_hash		hash;

	hash = hash_size4_triangle(triangle_maker);
	return (rotate_to_get_to_size4_formula(instructor, triangle_maker, hash) \
		|| size4_from_hash(instructor, hash));
}