/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 09:44:21 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/15 07:04:52 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "./libft/libft.h"
#include "./get_next_line/get_next_line.h"

int main()
{
	time_t t;
	srand((unsigned) time(&t));
	int r1 = rand() % 14;
	int r2 = rand() % 16;

	static int test_count = 1;

	char *line;
	if (test_count == 1)
	{
		int fd = open("testout1.txt", O_WRONLY);

		while (get_next_line(0, &line) == 1)
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		printf("8 2\n");
		close(fd);
		test_count++;
		return (1);
	}
	if (test_count == 2)
	{
		int fd = open("testout2.txt", O_WRONLY);

		while (get_next_line(0, &line) == 1)
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		test_count++;
		close(fd);
	}
	if(test_count == 3)
	{
		int fd = open("testout3.txt", O_WRONLY);

		while (get_next_line(0, &line) == 1)
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
			free(line);
		}
		test_count++;
		close(fd);

	}
		
	printf("%i %i\n", r1, r2);
	return (1);
}
