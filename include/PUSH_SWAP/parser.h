/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:14 by htsang            #+#    #+#             */
/*   Updated: 2023/02/23 23:38:19 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>

typedef struct s_push_swap_parser_collector
{
	int									value;
	struct s_push_swap_parser_collector	*next;
}				t_push_swap_parser_collector;

typedef struct s_push_swap_parser
{
	t_push_swap_parser_collector	*length;
	t_push_swap_parser_collector	*last;
}				t_push_swap_parser;

int								init_push_swap_parser(\
t_push_swap_parser *parser);

int								add_collector(t_push_swap_parser *parser, \
int value);

t_push_swap_parser_collector	*new_collector(int value);

void							clean_collectors(\
t_push_swap_parser_collector *head);

int								parse_number(const char **str, int *result);

t_push_swap_parser				*parse_from_cli(t_push_swap_parser *parser, \
int argc, const char **argv);

int								*to_array(t_push_swap_parser *parser, \
size_t *size);

#endif