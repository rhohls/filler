/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playgame.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:29:52 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/05 15:45:36 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include <fcntl.h>
#include <unistd.h>

void	mini_playgame(t_fill *game, char *line, int fd)
{
	//	ft_putstr_fd("getting pi\n", 2);
		get_piece(game, line, fd);
	//	ft_putstr_fd("adding heat\n",2);
	//	printstate(game, 0);
		edge_heat(game);
	//	ft_putstr_fd("deciding\n",2);
		decide(game);		
	//	printstate(game, 2);
	//	ft_putstr_fd("copying game\n",2);
		copy_game_map(game);
	//	ft_putstr_fd("reseting heat\n",2);
		reset_heat(game);
	//	ft_putstr_fd("placeing piece\n",2);
		place_piece(game);
}

t_fill	*play_game(int fd, t_fill *game)
{
	char			*line;
	int				ret;

	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (ft_strncmp(line, "Plateau", 7) == 0) //get board size
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
				init_maps(game);
			game->map[ft_atoi(line)] = (line + 4);
		}
		else if (line[0] == '*' || line[0] == '.') //get actual piece
		{
			mini_playgame(game, line, fd);

		}
	}
	return (game);
}


