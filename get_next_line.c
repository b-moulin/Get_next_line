/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:41:22 by bmoulin           #+#    #+#             */
/*   Updated: 2020/12/24 07:47:18 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_lor(char **buf, char *readbuf, int fd, int lor)
{
	int		realloc;
	size_t	i;

	i = 0;
	if (lor == 1)
	{
		while (readbuf[i])
			readbuf[i++] = '\0';
		if (!(realloc = read(fd, readbuf, BUFFER_SIZE)) ||
			realloc < BUFFER_SIZE)
			if (realloc <= BUFFER_SIZE)
			{
				readbuf[realloc] = '\0';
				return (realloc == -1 ? -1 : 0);
			}
		if (!(*buf = ft_strjoin(*buf, readbuf)))
			return (-1);
		return (1);
	}
	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	if (!(*buf)[i])
		return (0);
	return (1);
}

int		ft_cut_buf(char **buf)
{
	size_t	i;
	size_t	j;
	size_t	tmpi;
	size_t	start;
	char	*temp;

	i = 0;
	j = 0;
	while ((*buf)[i] && (*buf)[i] != '\n')
		i++;
	tmpi = (unsigned char)((*buf)[i]) == 190 ? 0 : 1;
	i++;
	start = i;
	while ((*buf)[i++])
		j++;
	if (!(temp = malloc(sizeof(char) * (j + 1))))
		return (-1);
	temp[j] = '\0';
	i = 0;
	while ((*buf)[start])
		temp[i++] = (*buf)[start++];
	free(*buf);
	*buf = temp;
	return (tmpi);
}

int		gnl_infinite_loop(char **buf, char *readbuf, char **line, int fd)
{
	int		realloc;

	if (ft_lor(&(*buf), readbuf, fd, 0) == 0)
	{
		if (!(realloc = ft_lor(&(*buf), readbuf, fd, 1)) || realloc < 0)
			if (realloc <= 0)
			{
				if ((*buf)[0] == -66)
					return (ft_free_buf(&(*buf), 0, &(*line), 1));
				if (!((*buf) = ft_strjoin((*buf), readbuf)))
					return (-1);
				if (ft_lor(&(*buf), readbuf, fd, 0) == 0)
					return ((!(*line = ft_strdup((*buf))))
						? -1 : ft_free_buf(&(*buf), 0, &(*line), 0));
				else if (ft_putbuf_inline((*buf), &(*line)) <= 0)
					return (-1);
				return (ft_cut_buf(&(*buf)));
			}
		return (realloc <= 0 ? -1 : 88);
	}
	else
		return ((ft_putbuf_inline((*buf), &(*line)) <= 0)
			? -1 : ft_cut_buf(&(*buf)));
}

int		ft_buf_is_null(char **buf, char **line, int fd, char *readbuf)
{
	int		realloc;
	int		i;

	i = -1;
	if (!(*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	(*buf)[BUFFER_SIZE] = '\0';
	realloc = read(fd, readbuf, BUFFER_SIZE);
	if (realloc < 0)
		return (ft_free_buf(&(*buf), -1, &(*line), 0));
	readbuf[realloc] = 0;
	if (realloc == 0)
		return (ft_free_buf(&(*buf), 0, &(*line), 1));
	if (fd < 0 || realloc <= 0 || fd > 4096)
		return (ft_free_buf(&(*buf), realloc == 0 ? 0 : -1, &(*line), 0));
	while (readbuf[++i] != 0)
		(*buf)[i] = readbuf[i];
	(*buf)[i] = 0;
	if (realloc < BUFFER_SIZE)
	{
		if (ft_lor(&(*buf), readbuf, fd, 0) != 0)
			return ((ft_putbuf_inline(readbuf, &(*line)) <= 0)
				? -1 : ft_cut_buf(&(*buf)));
	}
	return (88);
}

int		get_next_line(int fd, char **line)
{
	char			readbuf[BUFFER_SIZE + 1];
	int				realloc;
	static char		*buf[4096];

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	readbuf[BUFFER_SIZE] = '\0';
	if (!(buf[fd]) || buf[fd][0] == 0)
	{
		realloc = ft_buf_is_null(&(buf[fd]), &(*line), fd, readbuf);
		if (realloc != 88)
			return (realloc);
	}
	while (1)
	{
		realloc = gnl_infinite_loop(&(buf[fd]), readbuf, &(*line), fd);
		if (realloc != 88)
		{
			if (!(buf[fd]) || buf[fd][0] == '\0')
				ft_free_buf(&(buf[fd]), 0, &(*line), 0);
			return (realloc);
		}
	}
	return (1);
}
