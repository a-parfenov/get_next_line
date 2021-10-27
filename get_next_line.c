/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 18:08:03 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/27 22:46:00 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remains(char *rem_old)
{
	int		i;
	int		j;
	char	*remains;

	i = 0;
	while (rem_old[i] && rem_old[i] != '\n')
		++i;
	if (!rem_old[i])
	{
		free(rem_old);
		return (NULL);
	}
	remains = (char *)malloc(sizeof(char) * (ft_strlen(rem_old) - i + 1));
	if (!remains)
		return (NULL);
	++i;
	j = 0;
	while (rem_old[i])
		remains[j++] = rem_old[i++];
	remains[j] = '\0';
	free(rem_old);
	return (remains);
}

char	*ft_get_line(char *remains)
{
	int		i;
	char	*line;

	i = 0;
	if (!remains[i])
		return (NULL);
	while (remains[i] && remains[i] != '\n')
		++i;
	line = (char *)malloc(sizeof(char) * (i + 1));
	if (!line)
		return (NULL);
	i = -1;
	while (remains[++i] && remains[i] != '\n')
		line[i] = remains[i];
	if (remains[i] == '\n')
	{
		line[i] = remains[i];
		++i;
	}
	line[i] = '\0';
	return (line);
}

char	*ft_read_save(int fd, char *remains)
{
	char	*buff;
	int		read_buff;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	read_buff = 1;
	while (!ft_strchr(remains, '\n') && read_buff != 0)
	{
		read_buff = read(fd, buff, BUFFER_SIZE);
		if (read_buff == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[read_buff] = '\0';
		remains = ft_strjoin_gnl(remains, buff);
	}
	free(buff);
	return (remains);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remains;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	remains = ft_read_save(fd, remains);
	if (!remains)
		return (NULL);
	line = ft_get_line(remains);
	remains = ft_remains(remains);
	return (line);
}
