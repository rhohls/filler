/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_trim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 06:55:54 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/05 15:47:34 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void	rm_row_top(t_fill *game)
{
	int row;

	row = 0;
	while (row < game->ROW(p_size) - 1)
	{
		game->piece[row] = game->piece[row + 1];
		row++;
	}
}

static void	trim_top(t_fill *game, int row, int col)
{
	int max_row;

	max_row = game->ROW(p_size);
	row = 0;
	while (row < max_row)
	{
		col = 0;
		while (col < game->COL(p_size))
		{
			if (game->piece[0][col] == '*')
				return ;
			col++;
		}
		rm_row_top(game);
		game->ROW(trimmed)++;
		game->ROW(p_size)--;
		row++;
	}
}

static void	trim_bottom(t_fill *game, int row, int col)
{
	row = game->ROW(p_size) - 1;
	while (row >= 0)
	{
		col = game->COL(p_size) - 1;
		while (col >= 0)
		{
			if (game->piece[row][col] == '*')
				return ;
			col--;
		}
		game->ROW(p_size)--;
		row--;
	}
}

void		trim_piece(t_fill *game)
{
	int		row;
	int		col;

	row = 0;
	col = 0;
	trim_bottom(game, row, col);
	trim_right(game, row, col);
	trim_top(game, row, col);
	trim_left(game, row, col);
	return ;
}
