/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabrugie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 11:18:42 by sabrugie          #+#    #+#             */
/*   Updated: 2019/11/01 17:28:05 by sabrugie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_remain(int fd, char **remain)
{
	free(remain[fd]);
	remain[fd] = NULL;
}

int		get_read(int fd, char **remain, char **line)
{
	int		i;
	int		nl;

	if (!remain[fd] || !remain)
		return (0);
	i = 0;
	if (!(*line = ft_cut(remain[fd])))
	{
		return (-1);
	}
	while (remain[fd][i])
		i++;
	if ((nl = has_nl(remain[fd])))
	{
		if (!(remain[fd] = to_next(fd, remain, remain[fd], i)))
			return (-1);
		return ((!*line || !nl) ? 0 : 1);
	}
	//free_remain(fd, remain);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int			nl;
	int			ret;
	int			to_ret;
	char		buf[BUFFER_SIZE + 1];
	static char	*remain[OPEN_MAX];

	if ((to_ret = get_read(fd, remain, line)) == 0)
	{
		while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
		{
			buf[ret] = 0;
			if (!(*line = ft_join(*line, buf)))
				return (-1);
			if ((nl = has_nl(buf)))
				break ;
		}
		if (!(remain[fd] = to_next(fd, remain, buf, ret)))
			return (-1);
		to_ret = ((!*line || !ret || !nl) ? 0 : 1);
	}
	if (to_ret == 0 && remain[fd])
		free_remain(fd, remain);
	return (to_ret);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*line = 0;
	
	(void)ac;
	(void)av;
	while (1)
	{
		fd = open("get_next_line.c", O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			printf("%s\n", line);
			free(line);
		}
		close(fd);
	}
	//system("leaks a.out");
	return (0);
}
