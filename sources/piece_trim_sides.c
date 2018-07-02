/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   piece_trim_sides.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 09:28:53 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/02 14:50:33 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../filler.h"

static void rm_col_right(t_fill *game, int col_rm)
{
	int row;
	int col;

	row = 0;
	while (row < game->ROW(p_size))
	{
		game->piece[row][col_rm] = '\0';
		row++;
	}
}

static void rm_col_left(t_fill *game)
{
	int row;
	char	*temp;

	row = 0;
	while (row < game->ROW(p_size))
	{
		temp = game->piece[row];
		game->piece[row] = ft_strdup(&(game->piece[row][1]));
//		free(temp);
		row++;
	}
}

void trim_right(t_fill *game, int row, int col)
{
	col = game->COL(p_size) - 1;
	while (col >= 0)
	{
		row = game->ROW(p_size) - 1;
		while (row >= 0)
		{
			if (game->piece[row][col] == '*')
				return ;
			row--;
		}
		rm_col_right(game, col);
		game->COL(p_size)--;
		col--;
	}
}

void trim_left(t_fill *game, int row, int col)
{
	col =  0;
	while (col < game->COL(p_size))
	{
		row = 0;
		while (row < game->ROW(p_size))
		{
			if (game->piece[row][0] == '*')
				return ;
			row++;
		}
		rm_col_left(game);
		game->COL(trimmed)++;
		game->COL(p_size)--;
		col++;
	}
}


