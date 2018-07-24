/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_location.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 07:03:12 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/03 07:06:42 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int	quadrant(t_fill *game, int row, int col)
{
	if (col >= (game->COL(m_size) / 2) && row >= (game->ROW(m_size) / 2))
		return (4);
	else if (col >= (game->COL(m_size) / 2) && row < (game->ROW(m_size) / 2))
		return (1);
	else if (col < (game->COL(m_size) / 2) && row < (game->ROW(m_size) / 2))
		return (2);
	else if (col < (game->COL(m_size) / 2) && row >= (game->ROW(m_size) / 2))
		return (3);
	return (0);
}

int			*op_location(t_fill *game)
{
	int ret[2];
	int row;
	int col;
	int *ptr;

	row = 0;
	while (row < game->ROW(m_size))
	{
		col = 0;
		while (col < game->COL(m_size))
		{
			if ((game->old_map) && (game->map[row][col] == game->op_sym[0]) &&
					(game->map[row][col] != game->old_map[row][col]))
			{
				ret[0] = row;
				ret[1] = col;
				return (ptr = ret);
			}
			col++;
		}
		row++;
	}
	return (NULL);
}

int			op_quadrant(t_fill *game)
{
	int *pos;

	pos = op_location(game);
	if (pos)
		return (quadrant(game, pos[0], pos[1]));
	else
		return (-1);
}

void		place_smallmap(t_fill *game)
{
	int row;
	int col;

	row = 0;
	while (row < game->ROW(m_size))
	{
		col = game->COL(m_size);
		while (col >= 0)
		{
			if (valid_move_static(game, row, col))
			{
				if (row == 0)
					game->top = 0;
				adj_place_vals(game, row, col);
				return ;
			}
			col--;
		}
		row++;
	}
	fill_up(game);
}
