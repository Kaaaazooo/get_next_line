/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:28:55 by sabrugie          #+#    #+#             */
/*   Updated: 2019/10/24 12:12:10 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_read(char **tmp, int fd)
{
	int				next;
	char			*str;

	next = 0;
	str = 0;
	if (!tmp[fd])
		return (0);
	if (tmp[fd] && tmp[fd][0] != 0 && tmp[fd][0] != '\n')
	{
		str = ft_strdup(tmp[fd]);
		if (ft_strchr(tmp[fd], '\n'))
		{
			while (tmp[fd][next] != '\n')
				next++;
			tmp[fd] = tmp[fd] + next + 1;
			return (str);
		}
	}
	tmp[fd] = 0;
	free(tmp[fd]);
	return (str);
}

void	find_next(char buf[BUF_SIZE + 1], char **tmp, int fd, int ret)
{
	int				next;

	next = 0;
	while (ret && buf[next] != '\n' && buf[next] && next < ret)
		next++;
	if (next + 1 != ret && buf[next + 1] && ret)
		tmp[fd] = ft_strdup(buf + next + 1);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUF_SIZE + 1];
	static char		*tmp[10240];
	char			*str;
	int				ret;

	if (fd < 0 || line == NULL)
		return (-1);
	str = get_read(tmp, fd);
	if (str && ft_strchr(str, '\n'))
	{
		*line = ft_strtrim(str);
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		buf[ret] = 0;
		if (!(str = ft_strjoin(str, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	if (!(*line = ft_strtrim(str)))
		return (-1);
	find_next(buf, tmp, fd, ret);
	return ((str ? 1 : 0));
}
