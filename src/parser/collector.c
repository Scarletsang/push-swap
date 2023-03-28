/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collector.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 21:47:36 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:15:05 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP/parser.h"

void	collector_free_all(t_push_swap_parser_collector *head)
{
	t_push_swap_parser_collector	*next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

t_push_swap_parser_collector	*collector_create(int value)
{
	t_push_swap_parser_collector	*collector;

	collector = malloc(sizeof(t_push_swap_parser_collector));
	if (!collector)
	{
		return (NULL);
	}
	collector->value = value;
	collector->next = NULL;
	return (collector);
}
