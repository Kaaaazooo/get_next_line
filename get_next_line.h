/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 16:10:01 by sabrugie          #+#    #+#             */
/*   Updated: 2019/10/23 19:32:28 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUF_SIZE 32

int			get_next_line(int fd, char **line);
void		*ft_memcpy(void *dst, const void *src, size_t n);
char		*ft_strtrim(char *s1);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strchr(const char *s, int c);
#endif
