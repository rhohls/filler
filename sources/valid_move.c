/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_valid_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:23:46 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/03 07:41:36 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int	valid_check(t_fill *game, int row, int col, int *pos)
{
	int valid;

	valid = 2;
	row = 0;
	while (row < game->ROW(p_size))
	{
		col = 0;
		while (col < game->COL(p_size))
		{
			if ((game->map[ROW(pos) + row][COL(pos) + col] == game->op_sym[0]
				&& game->piece[row][col] == '*') ||
				(game->map[ROW(pos) + row][COL(pos) + col] == game->op_sym[1]
				&& game->piece[row][col] == '*'))
				return (0);
			if ((game->map[ROW(pos) + row][COL(pos) + col] == game->sym) &&
				(game->piece[row][col] == '*'))
				valid--;
			if (valid < 1)
				return (0);
			col++;
		}
		row++;
	}
	return (valid);
}

int			valid_move(t_fill *game, int *pos)
{
	int row;
	int col;
	int valid;

	if ((ROW(pos) + game->ROW(p_size)) > game->ROW(m_size))
		return (0);
	else if ((COL(pos) + game->COL(p_size)) > game->COL(m_size))
		return (0);
	row = 0;
	col = 0;
	valid = valid_check(game, row, col, pos);
	if (valid == 1)
		return (1);
	else
		return (0);
}

int			valid_move_static(t_fill *game, int rowin, int colin)
{
	int pos[2];

	pos[0] = rowin;
	pos[1] = colin;
	return (valid_move(game, pos));
}
