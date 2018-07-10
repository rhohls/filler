/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 13:16:07 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/10 12:03:12 by rhohls           ###   ########.fr       */
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
   
	printf("                    TEST RESULTS\n");
	printf(".-\"-.     .-\"-.     .-\"-.     .-\"-.     .-\"-.     .-\"-.\n");
	printf("     \"-.-\"     \"-.-\"     \"-.-\"     \"-.-\"     \"-.-\"\n");

	game_state = play_game(fd);
	printstate(game_state, 0);

	
	printf("\n----------- CUSTOM TETS ---------\n\n");
	int res;
	
//	res = valid_move(game_state, game_state->place);
	res = valid_move_static(game_state, 4, 15);
	printf("valid_move res %i\n", res);
	
	
	add_heat_static(1, 15, game_state, 1);
	place_basic(game_state);
	

	return (1);
}

