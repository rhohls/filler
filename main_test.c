/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:16:07 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/22 14:23:12 by rhohls           ###   ########.fr       */
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
	int		buff = 80;
	char	str[buff];
	int		fd;
	int		readret;
	t_fill	*game_state;
	
	
	if ((fd = open("game.txt", O_RDONLY)) < 2)
	{
		printf("failed opening file\n");
		return (0);
	}			
    game_state = play_game(fd);

	printf("                    TEST RESULTS\n");
	printf(".-\"-.     .-\"-.     .-\"-.     .-\"-.     .-\"-.     .-\"-.\n");
	printf("     \"-.-\"     \"-.-\"     \"-.-\"     \"-.-\"     \"-.-\"\n");
	
	int res;
	res = valid_move(game_state, game_state->place);
	printf("valid_move res %i\n", res);
	
	
	
	return (1);
}

