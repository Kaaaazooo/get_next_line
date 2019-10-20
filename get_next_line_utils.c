/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:05:35 by sabrugie          #+#    #+#             */
/*   Updated: 2019/10/20 11:52:52 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (!d && !s)
		return (0);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_strndup(const char *s1, size_t n)
{
	unsigned int	i;
	char			*s2;

	if (!(s2 = malloc(sizeof(*s2) * (n + 1))))
		return (0);
	i = 0;
	while (i < n)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

int		find_newline(char *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strnjoin(char *s1, char *s2, int len1, int len2)
{
	char	*tmp;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (!s1 ? ft_strndup(s2, len2) : ft_strndup(s1, len1));
	if (!(tmp = malloc(sizeof(char) * (len1 * len2 + 1))))
		return (0);
	ft_memcpy(tmp, s1, len1);
	ft_memcpy(tmp + len1, s2, len2);
	tmp[len1 + len2] = 0;
	return (tmp);
}
