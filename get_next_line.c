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

int		get_next_line(int fd, char **line)
{
	int				ret;
	static int		size;
	char			buf[BUF_SIZE];
	char			*str;
	int				end;

	size = 0;
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		end = find_newline(buf, ret);
		str = ft_strnjoin(str, buf, size, ret);
		size += ret;
		if (end != ret)
			break ;
	}
	*line = str;
	return ((str) ? 1 : 0);
}

int		main(int ac, char **av)
{
	char	*str;

	(void)ac;
	str = 0;
	printf("read ? %d\n", get_next_line(open(av[1], O_RDONLY), &str));
	printf("%s", str);
	return (0);
}
