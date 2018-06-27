/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:33:00 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/27 15:22:45 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	gen_heatmap(t_fill *game)
{	
	game->heat_map = (int **)malloc(sizeof(int *) * game->ROW(m_size));
	int	count = 0;
	while (count < game->ROW(m_size))
	{
		game->heat_map[count] = (int *)malloc(sizeof(int) * game->COL(m_size));
//		ft_bzero(game->heat_map[count],game->COL(m_size));
		count++;
	}
}

void	gen_map(t_fill *game)
{	
	game->map = (char **)malloc(sizeof(char *) * game->ROW(m_size));
}

void	gen_piece(t_fill *game)
{	
	game->piece = (char **)malloc(sizeof(char *) * game->ROW(p_size));
}

void	get_piece(t_fill *game, char *line, int fd)
{
	int	i;

	i = 0;
	gen_piece(game);

	game->piece[i] = line;
	i++;
	while (i <= (game->ROW(p_size) - 1) && get_next_line(fd, &line))
	{
		game->piece[i] = line;
		i++;
	}
}
