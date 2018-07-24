/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 06:53:37 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/19 18:00:41 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <strings.h>
#include <fcntl.h>
#include "../includes/filler.h"

int main()
{
	int game_ret;
	int fd;
	
	fd = open("game.txt", O_RDONLY);
//	fd = 0;	
//	printf("calling \n");
	while (1)
	{
		game_ret = play_game(fd);
		printf("game ret %i\n", game_ret);
		if (game_ret <1)
			break;

	}
	
	//printf("finished \n");
	return (1);
}

