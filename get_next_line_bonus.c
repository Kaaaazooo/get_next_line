/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:18:42 by sabrugie          #+#    #+#             */
/*   Updated: 2019/11/10 12:06:49 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		end_reached(int ret, int fd, char **line, char **remain)
{
	if ((ret == 0 && !*line) || ret == -1)
	{
		free(remain[fd]);
		remain[fd] = NULL;
	}
	return (!ret ? 0 : -1);
}

int		get_read(int fd, char **remain, char **line)
{
	int		i;
	int		nl;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(*line = ft_cut("")))
		return (-1);
	if (!remain[fd] || !remain)
		return (0);
	i = 0;
	free(*line);
	if (!(*line = ft_cut(remain[fd])))
		return (-1);
	while (remain[fd][i])
		i++;
	if ((nl = has_nl(remain[fd])))
	{
		if (!(remain[fd] = to_next(fd, remain, remain[fd], i)))
			return (-1);
		return ((!*line || !nl) ? 0 : 1);
	}
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			ret;
	int			to_ret;
	char		*buf;
	static char	*remain[OPEN_MAX];

	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (end_reached(-1, fd, line, remain));
	if ((to_ret = get_read(fd, remain, line)) == 0)
	{
		while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[ret] = 0;
			if (!(*line = ft_join(*line, buf)))
				return (end_reached(-1, fd, line, remain));
			if ((has_nl(buf)))
				break ;
		}
		if (!(remain[fd] = to_next(fd, remain, buf, ret)))
			return (end_reached(-1, fd, line, remain));
		to_ret = ((!ret) ? 0 : 1);
	}
	end_reached(to_ret, fd, line, remain);
	free(buf);
	return (to_ret);
}
