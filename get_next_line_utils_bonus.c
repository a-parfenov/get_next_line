/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:09:48 by aleslie           #+#    #+#             */
/*   Updated: 2021/10/29 04:50:59 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	char	*str;

	str = (char *)s;
	while (*str != (unsigned char)c)
	{
		if (*str == '\0')
			return (NULL);
		str++;
	}
	return (str);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*mem;

	i = 0;
	j = 0;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	mem = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (mem == NULL)
		return (NULL);
	while (s1 && s1[i])
		mem[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i])
		mem[j++] = s2[i++];
	mem[j] = '\0';
	return (mem);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;

	i = 0;
	if (dstsize > 0)
	{
		while (i < (dstsize - 1) && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen((char *)src));
}

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	len;
	char	*mem;
	char	*str;

	str = (char *)s1;
	len = ft_strlen((char *)s1);
	mem = (char *)malloc(sizeof(char) * (len + 1));
	if (!mem)
		return (NULL);
	i = 0;
	while (i < len)
	{
		mem[i] = str[i];
		i++;
	}
	mem[i] = '\0';
	return (mem);
}
