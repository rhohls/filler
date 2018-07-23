/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:33:00 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/05 15:45:30 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void init_maps(t_fill *game)
{
	gen_map(game);
	gen_heatmap(game);
	game->initial++;
	reset_heat(game);
}
void	gen_heatmap(t_fill *game)
{
	int count;

	game->heat_map = (int **)malloc(sizeof(int *) * game->ROW(m_size));
	count = 0;
	while (count < game->ROW(m_size))
	{
		game->heat_map[count] = (int *)malloc(sizeof(int) * game->COL(m_size));
		count++;
	}
//	dprintf(2, "\nmap_size %i, count %i\n",game->ROW(m_size), count);
//	game->heat_map[0][0] = 1;
//	game->heat_map[0][1] = 1;
//	game->heat_map[0][2] = 1;
//	dprintf(2, "size of array == %zu\n", sizeof(game->heat_map[0]) / sizeof(game->heat_map[0][0]));
	reset_heat(game);
}

void	gen_map(t_fill *game)
{
	int count;

	game->map = (char **)malloc(sizeof(char *) * game->ROW(m_size));
	game->old_map = (char **)malloc(sizeof(char *) * game->ROW(m_size));
	count = 0;
	while (count < game->ROW(m_size))
		game->old_map[count++] = ft_strnew(game->COL(m_size));
}

void	get_piece(t_fill *game, char *line, int fd)
{
	int	i;

	i = 0;
	game->piece = (char **)malloc(sizeof(char *) * game->ROW(p_size));
	game->piece[i] = line;
	i++;
	while (i <= (game->ROW(p_size) - 1) && get_next_line(fd, &line))
	{
		game->piece[i] = line;
		i++;
	}
	trim_piece(game);
}

void	copy_game_map(t_fill *game)
{
	int row;

	row = 0;
	while (row < game->ROW(m_size))
	{
		game->old_map[row] = game->map[row];
		row++;
	}
}
