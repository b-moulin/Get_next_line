/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:35:25 by bmoulin           #+#    #+#             */
/*   Updated: 2020/12/24 07:31:55 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_free_buf(char **buf, int retopt, char **line, int lineon)
{
	if (lineon == 1)
	{
		if (!((*line) = malloc(sizeof(char))))
			return (-1);
		**line = 0;
	}
	if (buf)
	{
		free((*buf));
		(*buf) = 0;
	}
	return (retopt);
}

int		ft_putbuf_inline(char *buf, char **line)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (!((*line) = malloc(sizeof(char) * (i + 1))))
		return (-1);
	i = 0;
	(*line)[i] = '\0';
	while (buf[i] && buf[i] != '\n')
	{
		if (buf[i] != -66)
		{
			(*line)[j] = buf[i];
			j++;
		}
		i++;
	}
	i = 0;
	(*line)[j] = '\0';
	return (1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (i <= ft_strlen(s1) && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	while (j <= ft_strlen(s2) && s2[j])
	{
		dest[i] = s2[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	free(s1);
	return (dest);
}

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s1)
{
	int		i;
	char	*dest;

	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!dest)
		return (NULL);
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = s1[i];
	return (dest);
}
