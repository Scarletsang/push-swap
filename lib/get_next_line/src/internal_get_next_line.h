/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   internal_get_next_line.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htsang <htsang@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 22:08:36 by htsang            #+#    #+#             */
/*   Updated: 2023/03/28 19:10:16 by htsang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERNAL_GET_NEXT_LINE_H
# define INTERNAL_GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <unistd.h>
# include <stdlib.h>

char	*ft_strncpy(char *dest, const char *src, size_t n);

char	*ft_strljoin(char *target, char const *str, size_t len);

char	*ft_strdup(const char *str);

#endif