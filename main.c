/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aleslie <aleslie@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 17:57:32 by einterdi          #+#    #+#             */
/*   Updated: 2021/10/29 04:36:25 by aleslie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

#define COL0 "\e[1;38;2;200;;m"
#define COL1 "\e[1;38;2;;200;m"
#define COL2 "\e[1;38;2;;100;200m"
#define COL3 "\e[1;38;2;200;;200m"
#define UN "\e[m"

int	main(void)
{
	char	*str[10];
	char	*line;
	int		fd1;
	int		fd2;
	int		fd3;
	int		fd4;

	str[0] = "test1.txt";
	str[1] = "test2.txt";
	str[2] = "test3.txt";
	str[3] = "test4.txt";
	str[4] = NULL;
	fd1 = open(str[0], O_RDONLY);
	fd2 = open(str[1], O_RDONLY);
	fd3 = open(str[2], O_RDONLY);
	fd4 = open(str[3], O_RDONLY);
	for (size_t i = 0; i < 3; i++)
	{
		line = get_next_line(fd1);
		printf("%s : |%s%s%s|", str[0], COL0, line, UN);
		free(line);

		line = get_next_line(fd2);
		printf("%s : |%s%s%s|", str[1], COL1, line, UN);
		free(line);

		line = get_next_line(fd3);
		printf("%s : |%s%s%s|", str[2], COL2, line, UN);
		free(line);

		line = get_next_line(fd4);
		printf("%s : |%s%s%s|", str[3], COL3, line, UN);
		free(line);
	}
//gcc -Wall -Wextra -Werror -D BUFFER_SIZE=42 main.c get_next_line_bonus.c get_next_line_utils_bonus.c && ./a.out

	close(fd1);
	close(fd2);
	close(fd3);
	close(fd4);
	return (0);
}
