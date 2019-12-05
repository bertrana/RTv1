/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yjohns <yjohns@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 04:15:08 by yjohns            #+#    #+#             */
/*   Updated: 2019/11/06 04:15:08 by yjohns           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>

#define ERR_CODE -1

static char	*check_mem(char *mem, char **line)
{
	char *n;

	if (!mem)
	{
		*line = ft_strnew(1);
		return (NULL);
	}
	if ((n = ft_strchr(mem, '\n')))
	{
		*n = '\0';
		*line = ft_strdup(mem);
		mem = ft_strcpy(mem, n + 1);
		return (mem);
	}
	*line = ft_strdup(mem);
	free(mem);
	return (NULL);
}

static int	read_line(int fd, char **mem, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*n;
	char	*tmp;

	n = NULL;
	while (!mem[fd] && line && !n && (ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret < 0)
			return (ERR_CODE);
		buf[ret] = '\0';
		if ((n = ft_strchr(buf, '\n')))
		{
			*n = '\0';
			if (!(mem[fd] = ft_strdup(n + 1)))
				return (ERR_CODE);
		}
		tmp = *line;
		if (!(*line = ft_strjoin(*line, buf)))
			return (ERR_CODE);
		free(tmp);
	}
	return (!ret && !mem[fd] && !ft_strlen(*line) ? 0 : 1);
}

int			get_next_line(const int fd, char **line)
{
	static	char *mem[10240];

	if (fd < 0 || line == 0 || fd > 10240 || BUFF_SIZE < 1)
		return (ERR_CODE);
	mem[fd] = check_mem(mem[fd], line);
	if (!line)
		return (ERR_CODE);
	return (read_line(fd, mem, line));
}
