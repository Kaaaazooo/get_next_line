/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:32:33 by sabrugie          #+#    #+#             */
/*   Updated: 2019/10/23 19:24:28 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_strdup(const char *s1)
{
	size_t			i;
	char			*s2;

	i = 0;
	while (s1[i])
		i++;
	if (!(s2 = malloc(sizeof(*s2) * (i + 1))))
		return (0);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = 0;
	return (s2);
}

char	*ft_strchr(const char *s, int c)
{
	char			*str;

	str = (char *)s;
	while (*str)
	{
		if (*str == (char)c)
			return (str);
		str++;
	}
	if (c == 0)
		return (str);
	return (0);
}

char	*ft_strtrim(char *s1)
{
	size_t			end;
	size_t			i;
	char			*res;

	i = 0;
	end = 0;
	if (s1 == 0 || s1[0] == 0 || s1[0] == '\n')
		return (0);
	while (s1[end] != '\n' && s1[end])
		end++;
	if (!(res = malloc(sizeof(*res) * (end + 1))))
		return (0);
	res[end] = 0;
	while (i < end)
	{
		res[i] = s1[i];
		i++;
	}
	return (res);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char			*tmp;
	size_t			len1;
	size_t			len2;

	len1 = 0;
	len2 = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return ((!s1) ? ft_strdup(s2) : ft_strdup(s1));
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	if (!(tmp = malloc(sizeof(char) * (len1 + len2 + 1))))
		return (0);
	ft_memcpy(tmp, s1, len1);
	ft_memcpy(tmp + len1, s2, len2);
	tmp[len1 + len2] = 0;
	return (tmp);
}
