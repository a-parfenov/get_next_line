/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 05:32:20 by aleslie           #+#    #+#             */
/*   Updated: 2021/11/15 12:09:20 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*name(char *s)
{
	free(s);
	return (NULL);
}

char	*logic(char **buff, char *line, int fd)
{
	int		rd;
	char	read_buff[BUFFER_SIZE + 1];
	char	*p_n;
	char	*temp;

	rd = 1;
	while (!ft_strchr(line, '\n') && rd != 0)
	{
		rd = read(fd, read_buff, BUFFER_SIZE);
		if (rd == 0 && *line == '\0')
			return (name(line));
		if (rd == -1)
			return (name(*buff));
		read_buff[rd] = '\0';
		p_n = ft_strchr(read_buff, '\n');
		if (p_n)
		{
			*buff = ft_strdup(p_n + 1);
			*(p_n + 1) = '\0';
		}
		temp = line;
		line = ft_strjoin(line, read_buff);
		free(temp);
	}
	return (line);
}

int	not_buff(char **line)
{
	*line = malloc(sizeof(char));
	if (!*line)
		return (0);
	**line = '\0';
	return (1);
}

int	init(char **buff, char **line)
{
	char	*p_n;
	char	*tmp_buff;

	if (*buff)
	{
		p_n = ft_strchr(*buff, '\n');
		if (p_n)
		{
			tmp_buff = ft_strdup(p_n + 1);
			*(p_n + 1) = '\0';
			*line = ft_strdup(*buff);
			free(*buff);
			*buff = tmp_buff;
		}
		else
		{
			*line = *buff;
			*buff = NULL;
		}
	}
	else
		return (not_buff(line));
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buff[256];
	char		*line;
	int			check;

	line = NULL;
	if (read(fd, line, 0) < 0 || BUFFER_SIZE < 1)
		return (NULL);
	check = init(&buff[fd], &line);
	if (!check)
		return (NULL);
	line = logic(&buff[fd], line, fd);
	if (!line)
		return (NULL);
	return (line);
}
