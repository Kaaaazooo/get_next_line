/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:19:14 by sabrugie          #+#    #+#             */
/*   Updated: 2019/11/13 14:14:06 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int			get_next_line(int fd, char **line);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			has_nl(char *str);
char		*ft_cut(char *s1);
char		*ft_join(char *s1, char *s2);
char		*to_next(int fd, char **remain, char *buf, int ret);

#endif
