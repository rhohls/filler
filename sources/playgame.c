/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:29:52 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/19 18:00:37 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include <fcntl.h>
#include <unistd.h>
/* 
** 0 is none intial
** 1 is map intial
** 2 is heatmap
** 3 is both
*/

int	play_game(int fd)
{
	int		line_num;
	char	*line;
	static t_fill	*game;
	int		piece_row;

	if (!game)
	{
		game = (t_fill *)malloc(sizeof(t_fill));
		game->initial = 0;
	}
//	printf("starting\n");
	int loopcount = 0;
	int ret;
	int fd2 = open("game2.txt", O_RDONLY);
//	printf("gnl ret |%i| string |%s| \n", get_next_line(fd, &line), line);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		write( fd2, line, ft_strlen(line));
//		printf("gnl ret |%i| string |%s| \n",ret,line);
//		printf("game address %p\n", game);
//		printf("str res %i\n", ft_strncmp(line, "Plateau", 7));
		if (line[0] == '$') //initialize player symbol
		{
//			printf("1\n");
			game->sym = (line[10] == '1' ? 'O' : 'X');
			game->op_sym[0] = (line[10] == '2' ? 'O' : 'X');
			game->op_sym[1] = ft_tolower(game->op_sym[0]);

		}
		else if (ft_strncmp(line, "Plateau", 7) == 0) //get board size
		{
//			printf("2\n");
			game->ROW(m_size) = ft_atoi(&line[8]);
			game->COL(m_size) = ft_atoi(&line[8 + ft_nextdig(&line[8])]);
		}
		else if (ft_strncmp(line, "Piece", 5) == 0) // get piece size
		{
//			printf("3\n");
			game->ROW(p_size) = ft_atoi(&line[6]);
			game->COL(p_size) = ft_atoi(&line[6 + ft_nextdig(&line[6])]);
		}
		else if (ft_isdigit(line[0])) //get board
		{
//			printf("4\n");
			if (game->initial < 1)
			{
		//		printf("initialize map :%i:", game->initial);
				gen_map(game);
				game->initial++;
			}
		//	printf("row num for map |%i| line |%s|\n",ft_atoi(line),line + 4);
			game->map[ft_atoi(line)] = (line + 4);
		}
		else if (line[0] == '*' || line[0] == '.') //get actual piece
		{
			//-----add piece trim-----return negative-----//
			//wrap around is possible
//			printf("5\n");
			get_piece(game, line, fd);
//			printf("got piece\n");
		//	printstate(game);
			decide(game);
//			printf("decided\n");
			place_piece(game);
			printstate(game);
		}
	//	if (game->place[0] == -1)
	//		return (-1);
	//	else
	//		return (1);
	}
	close(fd2);
//	printf("realbad");
	return (0);
}



