/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:03:31 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/29 08:08:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include <stdio.h>

void	place_piece(t_fill *game)
{
	ft_putnbr(ROW(game->place));
	ft_putchar(' ');
	ft_putnbr(COL(game->place));
	ft_putchar('\n');
/*
	ft_putnbr_fd(ROW(game->place), 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(COL(game->place), 2);
	ft_putchar_fd('\n', 2);
*/	
	game->ROW(trimmed) = 0;
	game->COL(trimmed) = 0;
}
/*
** 0: heatmap val  1,2: row,col
*/
int highest_map(t_fill *game, int *vals)
{
	int row;
	int col;

	row = 0;
	while (row < game->ROW(m_size))
	{
		col = 0;
		while (col < game->COL(m_size))
		{
			if (game->heat_map[row][col] >= vals[0])
			{
				vals[0] = game->heat_map[row][col];
				vals[1] = row;
				vals[2] = col;
			}
			col++;
		}
		row++;
	}
//	printf("val: %i, row:%i col:%i\n", vals[0], vals[1], vals[2]);
	return (vals[0]);
}	

void	fill_up(t_fill *game)
{
	int row;
	int col;

	row = game->ROW(m_size);
	while (row >= 0)
	{
		col = game->COL(m_size);
		while (col >= 0)
		{
			if (valid_move_static(game, row, col))
			{
				game->ROW(place) = row - game->ROW(trimmed);
				game->COL(place) = col - game->COL(trimmed);
				return ;
			}
			col--;
		}
		row--;
	}
	game->ROW(place) = 0;
	game->COL(place) = 0;
	game->exit = 1;
}


void decide(t_fill *game)
{
	int vals[3];

	while (highest_map(game, vals) > 0)
	{
		game->heat_map[vals[1]][vals[2]] = 0;
		vals[0] = 0;
		if (valid_move_static(game, vals[1], vals[2]))
		{
			game->ROW(place) = vals[1] - game->ROW(trimmed);
			game->COL(place) = vals[2] - game->COL(trimmed);
			return ;
		}
	}
	place_basic(game);
}


// add very basic






