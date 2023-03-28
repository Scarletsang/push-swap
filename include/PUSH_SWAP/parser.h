/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:27:14 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 05:23:54 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <stdlib.h>

/////////////////////////////////////////////
////////     Collector interface     ////////
/////////////////////////////////////////////

/**
 * @brief A collector is a linked list of integers, acting as an intermediate
 * data structure to store the parsed integers before converting them to an
 * array.
 */
typedef struct s_push_swap_parser_collector
{
	int									value;
	struct s_push_swap_parser_collector	*next;
}				t_push_swap_parser_collector;

t_push_swap_parser_collector	*collector_create(int value);

void							collector_free_all(\
t_push_swap_parser_collector *head);

///////////////////////////////////////////////
////////    The command line parser    ////////
///////////////////////////////////////////////

/**
 * @brief A parser that parse intergers from the input string to collectors,
 * then converts the collectors to an array.
 */
typedef struct s_push_swap_cli_parser
{
	t_push_swap_parser_collector	*length;
	t_push_swap_parser_collector	*last;
}				t_push_swap_cli_parser;

int								cli_parser_init(\
t_push_swap_cli_parser *parser);

int								cli_parser_add_collector(\
t_push_swap_cli_parser *parser, int value);

int								cli_parser_parse_number(\
const char **str, int *result);

t_push_swap_cli_parser			*cli_parser_parse_from_cli(\
t_push_swap_cli_parser *parser, int argc, const char **argv);

/**
 * @brief Convert the collectors to an array.
 * @param parser The command line parser
 * @param size A pointer to store the size of the parsed array. This is needed
 * because an interger array cannot be NULL-terminated since 0 is a valid element
 * of the array.
 * @return An interger array containing the parsed integers.
 */
int								*cli_parser_to_array(\
t_push_swap_cli_parser *parser, unsigned int *size);

#endif