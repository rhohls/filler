/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_move.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/02 12:45:56 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/03 06:57:15 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

/*
**  1234
** 1...o
** 2...o
** 3...o
** 4oooo
** only check the 'o'
**
** Place trim reasigns the place piece with trimmed vals
*/

int	right_up_complex(t_fill *game, int curr_row, int curr_col)
{
	int row;
	int col;

	col = game->COL(m_size);
	while (col >= curr_col)
	{
		if (valid_move_static(game, curr_row, col))
		{
			adj_place_vals(game, curr_row, col);
			return (1);
		}
		col--;
	}
	row = 0;
	while (row <= curr_row)
	{
		if (valid_move_static(game, row, curr_col))
		{
			adj_place_vals(game, row, curr_col);
			return (1);
		}
		row++;
	}
	return (0);
}

int	left_up_complex(t_fill *game, int curr_row, int curr_col)
{
	int row;
	int col;

	col = 0;
	while (col <= curr_col)
	{
		if (valid_move_static(game, curr_row, col))
		{
			adj_place_vals(game, curr_row, col);
			return (1);
		}
		col++;
	}
	row = 0;
	while (row <= curr_row)
	{
		if (valid_move_static(game, row, curr_col))
		{
			adj_place_vals(game, row, curr_col);
			return (1);
		}
		row++;
	}
	return (0);
}

int	left_down_complex(t_fill *game, int curr_row, int curr_col)
{
	int row;
	int col;

	col = 0;
	while (col <= curr_col)
	{
		if (valid_move_static(game, curr_row, col))
		{
			adj_place_vals(game, curr_row, col);
			return (1);
		}
		col++;
	}
	row = game->ROW(m_size);
	while (row >= curr_row)
	{
		if (valid_move_static(game, row, curr_col))
		{
			adj_place_vals(game, row, curr_col);
			return (1);
		}
		row--;
	}
	return (0);
}

int	right_down_complex(t_fill *game, int curr_row, int curr_col)
{
	int row;
	int col;

	col = game->COL(m_size);
	while (col >= curr_col)
	{
		if (valid_move_static(game, curr_row, col))
		{
			adj_place_vals(game, curr_row, col);
			return (1);
		}
		col--;
	}
	row = game->ROW(m_size);
	while (row >= curr_row)
	{
		if (valid_move_static(game, row, curr_col))
		{
			adj_place_vals(game, row, curr_col);
			return (1);
		}
		row--;
	}
	return (0);
}
