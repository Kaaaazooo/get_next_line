/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 14:28:55 by sabrugie          #+#    #+#             */
/*   Updated: 2019/10/23 19:32:22 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"
#include <stdio.h>
#include <fcntl.h>

char	*get_read(char **tmp, int fd)
{
	int				next;
	char			*str;

	next = 0;
	if (!tmp[fd])
		return (0);
	if (tmp[fd][0] != 0)
		str = ft_strdup(ft_strtrim(tmp[fd]));
	if (ft_strchr(tmp[fd], '\n'))
	{
		while (tmp[fd][next] != '\n')
			next++;
		tmp[fd] = tmp[fd] + next + 1;
		return (str);
	}
	else
	{
		tmp[fd] = 0;
		free(tmp[fd]);
	}
	return (0);
}

void	find_next(char buf[BUF_SIZE + 1], char **tmp, int fd, int ret)
{
	int				next;

	next = 0;
	while (buf[next] != '\n' && next < ret)
		next++;
	if (next + 1 != ret)
		tmp[fd] = ft_strdup(buf + next + 1);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUF_SIZE + 1];
	static char		*tmp[10240];
	char			*str;
	int				ret;
	int				next;

	next = 0;
	str = 0;
	if (!fd)
		return (-1);
	if ((str = get_read(tmp, fd)))
	{
		*line = str;
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = 0;
		if (!(str = ft_strjoin(str, buf)))
			return (-1);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	*line = ft_strtrim(str);
	find_next(buf, tmp, fd, ret);
	return ((str ? 1 : 0));
}

/*
**
**int		main(int ac, char **av)
**{
**	char	*str = 0;
**	int		fd = open(av[1], O_RDONLY);
**	int		fd1 = open(av[2], O_RDONLY);
**
**	(void)ac;
**	printf("read ? %d\n", get_next_line(fd, &str));
**	printf("%s\n", str);
**	printf("read ? %d\n", get_next_line(fd1, &str));
**	printf("%s\n", str);
**	printf("read ? %d\n", get_next_line(fd, &str));
**	printf("%s\n", str);
**	printf("read ? %d\n", get_next_line(fd1, &str));
**	printf("%s\n", str);
**	printf("read ? %d\n", get_next_line(fd, &str));
**	printf("%s\n", str);
**	return (0);
**}
**
*/
