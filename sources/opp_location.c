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

int			op_location(t_fill *game)
{
	int row;
	int col;

	row = 0;
	while (row < game->ROW(m_size))
	{
		col = 0;
		while (col < game->COL(m_size))
		{
			if ((game->old_map) && (game->map[row][col] == game->op_sym[0]) &&
					(game->map[row][col] != game->old_map[row][col]))
			{
				return (quadrant(game, row, col));
			}
			col++;
		}
		row++;
	}
	return (-1);
}
