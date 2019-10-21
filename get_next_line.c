/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:25:36 by sabrugie          #+#    #+#             */
/*   Updated: 2019/10/20 13:54:42 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int		get_line(char **str, char **line, int fd)
{
	unsigned int	i;

//	printf("%s", str[fd]);
	i = 0;
	if (!str[fd])
	{
		*line = 0;
		return (0);
	}
	while (str[fd][i] && str[fd][i] != '\n')
	{
		//printf("str[%d] = %c\n", i , str[fd][i]);
		i++;
	}
	if (!(*line = ft_strndup(str[fd], i)))
		return (-1);
	str[fd] = &str[fd][i + 1];
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	int				size;
	char			buf[BUF_SIZE];
	static char		*str[125];
	int				check;

	size = 0;

	if (fd == -1)
		return (-1);
	if (!str[fd])
	{
		while ((ret = read(fd, buf, BUF_SIZE)))
		{
			if (!(str[fd] = ft_strnjoin(str[fd], buf, size, ret)))
				return (-1);
			size += ret;
		}
	}
	if ((check = get_line(str, line, fd) == -1))
		return (-1);
	else if (check == 0)
		return (0);
	return ((str[fd]) ? 1 : 0);
}

int		main(int ac, char **av)
{
	char	*str;

	(void)ac;
	str = 0;
	int		fd = open(av[1], O_RDONLY);
	printf("read ? %d\n", get_next_line(fd, &str));
	printf("%s\n", str);
	printf("ok\n");
	printf("read ? %d\n", get_next_line(fd, &str));
	printf("%s", str);
	return (0);
}