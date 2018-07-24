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
	get_piece(game, line, fd);
	edge_heat(game);
	decide(game);
	copy_game_map(game);
	reset_heat(game);
	place_piece(game);
}

t_fill	*play_game(int fd, t_fill *game)
{
	char			*line;
	int				ret;

	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			game->ROW(m_size) = ft_atoi(&line[8]);
			game->COL(m_size) = ft_atoi(&line[8 + ft_nextdig(&line[8])]);
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			game->ROW(p_size) = ft_atoi(&line[6]);
			game->COL(p_size) = ft_atoi(&line[6 + ft_nextdig(&line[6])]);
		}
		else if (ft_isdigit(line[0]))
		{
			if (game->initial < 1)
				init_maps(game);
			game->map[ft_atoi(line)] = (line + 4);
		}
		else if (line[0] == '*' || line[0] == '.')
			mini_playgame(game, line, fd);
	}
	return (game);
}
