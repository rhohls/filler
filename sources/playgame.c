/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:29:52 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/22 14:48:19 by rhohls           ###   ########.fr       */
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

t_fill	*play_game(int fd)
{
	int				line_num;
	char			*line;
	static t_fill	*game;
	int				piece_row;
	int				ret;

	if (!game)
	{
		game = (t_fill *)malloc(sizeof(t_fill));
		game->initial = 0;
	}

	int fd2;
	fd2 = open("gamestate.txt", O_RDWR);
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		write(fd2, line, strlen(line));
		write(fd2, "\n", 1);

//		fprintf(stderr, "gnl ret |%i| string |%s| \n",ret,line);
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
//			ft_putstr_fd("getting pi\n", 2);
//			printf("5\n");
			get_piece(game, line, fd);
//			ft_putstr_fd("got piece\n",2);
		//	printstate(game);
			decide(game);
//			ft_putstr_fd("decided\n",2);
			place_piece(game);
//			ft_putstr_fd("postplace\n", 2);
			
//			printstate(game, 2);
		}
	}
	close(fd2);
	return (game);
}


