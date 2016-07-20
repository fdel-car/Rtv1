/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdel-car <fdel-car@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 16:42:18 by fdel-car          #+#    #+#             */
/*   Updated: 2016/03/16 22:04:16 by fdel-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

static int	ft_poscr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

static int	ft_unload(char **line, char end[256][BUFF_SIZE], int fd)
{
	*line = ft_strndup(end[fd], ft_poscr(end[fd]));
	ft_strcpy(end[fd], end[fd] + ft_poscr(end[fd]) + 1);
	return (1);
}

static int	ft_unload_bis(char end[256][BUFF_SIZE], int fd)
{
	ft_bzero(end[fd], BUFF_SIZE);
	return (1);
}

static int	ft_unload_final(char **line, char end[256][BUFF_SIZE],
		int fd, char buff[BUFF_SIZE])
{
	char *temp;

	temp = ft_strndup(buff, ft_poscr(buff));
	if (!(*line = ft_strjoin_free(*line, temp)))
		return (-1);
	free(temp);
	ft_strcpy(end[fd], ft_strchr(buff, '\n') + 1);
	return (1);
}

int			get_next_line(int const fd, char **line)
{
	static char end[256][BUFF_SIZE];
	char		buff[BUFF_SIZE + 1];
	int			i;

	if (fd < 0 || fd > 256 || !line || BUFF_SIZE < 1)
		return (-1);
	if (!(*line = end[fd] ? ft_strdup(end[fd]) : ft_strnew(1)))
		return (-1);
	if (ft_strchr(*line, '\n'))
		return (ft_unload(line, end, fd));
	while ((i = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[i] = '\0';
		if (ft_strchr(buff, '\n'))
			return (ft_unload_final(line, end, fd, buff));
		if (!(*line = ft_strjoin_free(*line, buff)))
			return (-1);
	}
	if (i == -1)
		return (-1);
	if (*line[0] != '\0')
		return (ft_unload_bis(end, fd));
	return (0);
}
