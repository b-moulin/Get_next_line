/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoulin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 13:33:34 by bmoulin           #+#    #+#             */
/*   Updated: 2020/12/24 07:33:21 by bmoulin          ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *s1);
int		ft_putbuf_inline(char *buf, char **line);
int		ft_cut_buf(char **buf);
int		ft_free_buf(char **buf, int retopt, char **line, int lineon);
int		gnl_infinite_loop(char **buf, char *readbuf, char **line, int fd);
int		ft_buf_is_null(char **buf, char **line, int fd, char *readbuf);
int		get_next_line(int fd, char **line);
int		ft_lor(char **buf, char *readbuf, int fd, int lor);

#endif
