/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 06:53:37 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/19 07:19:17 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <strings.h>
#include <fcntl.h>
#include "filler.h"

int main()
{
	int buff = 80;
	char str[buff + 1];
	int fd;
	int readret;

	bzero(str, buff + 1);
	fd = open("game.txt", O_RDONLY);

	while ((readret = read(fd, str, buff)) > 0)
	{
		write(0, str, readret);
		bzero(str, buff + 1);
	}
	play_game();
	return (1);
}

