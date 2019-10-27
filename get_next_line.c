/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:08:53 by sabrugie          #+#    #+#             */
/*   Updated: 2019/10/27 16:14:29 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "get_next_line_utils.c"

int		get_tmp(char *str, int ret, char *tmp[10240], int fd)
{
	int			i;

	i = 0;
	tmp[fd] = 0;
	while (str[i] && str[i] != '\n' && i < ret)
		i++;
	if (i + 1 != ret && str[i + 1] && ret)
		if (!(tmp[fd] = ft_strdup(str + i + 1)))
			return (0);
	return (1);
}

int		get_read(char *tmp[10240], char **line, char **str, int fd)
{
	int			next;

	next = 0;
	if (!tmp[fd])
		return (0);
	if (tmp[fd] && tmp[fd][0] != 0)
	{
		if (ft_strchr(tmp[fd], '\n'))
		{
			while (tmp[fd][next] && tmp[fd][next] != '\n')
				next++;
			if (!(*line = ft_strtrim(tmp[fd])))
				return (-1);
			tmp[fd] = tmp[fd] + next + 1;
			return (1);
		}
		if (!(*str = ft_strdup(tmp[fd])))
			return (-1);
	}
	tmp[fd] = NULL;
	free(tmp[fd]);
	return (0);
}

int		read_file(int fd, char **line, char *tmp[10240])
{
	char		buf[BUFFER_SIZE + 1];
	int			ret;
	int			to_ret;
	char		*str;

	str = 0;
	*line = 0;
	free(*line);
	if ((to_ret = get_read(tmp, line, &str, fd) != 0))
		return (to_ret);
	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = 0;
		str = ft_strjoin(str, buf, ret);
		if (ft_strchr(buf, '\n'))
			break ;
	}
//	printf("ret = %d ; str :\n%s\nbuf :\n%s\n", ret, str, buf);
	if (!(*line = ft_strtrim(str)) && ret != 0)
		return (-1);
	if (!get_tmp(buf, ret, tmp, fd))
		return (-1);
	free(str);
	return (*line ? 1 : 0);
}

int		get_next_line(int fd, char **line)
{
	char		*tmp[10240];
	int			to_ret;

	to_ret = read_file(fd, line, tmp);
	if (to_ret != 1)
	{
		*line = 0;
		free(*line);
		tmp[fd] = 0;
		free(tmp[fd]);
	}
	return (to_ret);
}
/*
int		main(int ac, char **av)
{
	int			fd;
	char		*str = 0;
	int			ret;
	(void)ac;
	(void)av;

//	while (1)
//	{
		fd = open("tests", O_RDONLY);
		while ((ret = get_next_line(fd, &str) > 0))
		{
			printf("%s\n", str);
		}
		close(fd);
	system("leaks a.out");
//	}
	return (0);
}*/
