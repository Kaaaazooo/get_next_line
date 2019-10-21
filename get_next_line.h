/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 16:50:53 by sabrugie          #+#    #+#             */
/*   Updated: 2019/10/20 12:13:48 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 13
# include <unistd.h>
# include <stdlib.h>

int			get_next_line(int fd, char **line);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			find_newline(char *s, int n);
char        *ft_strdup(const char *s1);
char		*ft_strndup(const char *s1, size_t n);
char		*ft_strnjoin(char *s1, char *s2, int len1, int len2);
#endif
