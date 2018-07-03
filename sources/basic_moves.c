/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:44:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/03 06:56:20 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

/*
** see bottom for direction decision
** starting in a corner check for valid move along a row or col
** see complex moves
*/

static void	right_up(t_fill *game)
{
	int row;
	int col;

	row = 0;
	col = game->COL(m_size);
	while (row < game->ROW(m_size) || col > 0)
	{
		row = (row <= game->ROW(m_size) ? row : game->ROW(m_size));
		col = (row <= game->COL(m_size) ? col : 0);
		if (right_up_complex(game, row, col))
			return ;
		row++;
		col--;
	}
	game->ROW(place) = 0;
	game->COL(place) = 0;
	game->exit = 1;
}

static void	left_up(t_fill *game)
{
	int row;
	int col;

	row = 0;
	col = 0;
	while (row < game->ROW(m_size) || col < game->COL(m_size))
	{
		row = (row <= game->ROW(m_size) ? row : game->ROW(m_size));
		col = (row <= game->COL(m_size) ? col : game->COL(m_size));
		if (left_up_complex(game, row, col))
			return ;
		row++;
		col++;
	}
	game->ROW(place) = 0;
	game->COL(place) = 0;
	game->exit = 1;
}

static void	left_down(t_fill *game)
{
	int row;
	int col;

	row = game->ROW(m_size);
	col = 0;
	while (row > 0 || col < game->COL(m_size))
	{
		row = (row <= game->ROW(m_size) ? row : 0);
		col = (row <= game->COL(m_size) ? col : game->COL(m_size));
		if (left_down_complex(game, row, col))
			return ;
		row--;
		col++;
	}
	game->ROW(place) = 0;
	game->COL(place) = 0;
	game->exit = 1;
}

static void	right_down(t_fill *game)
{
	int row;
	int col;

	row = game->ROW(m_size);
	col = game->COL(m_size);
	while (row > 0 || col < 0)
	{
		row = (row <= game->ROW(m_size) ? row : 0);
		col = (row <= game->COL(m_size) ? col : 0);
		if (right_down_complex(game, row, col))
			return ;
		row--;
		col--;
	}
	game->ROW(place) = 0;
	game->COL(place) = 0;
	game->exit = 1;
}

void		place_basic(t_fill *game)
{
	int quad;

	quad = op_location(game);
	if (quad == 1)
		right_up(game);
	else if (quad == 2)
		left_up(game);
	else if (quad == 3)
		left_down(game);
	else if (quad == 4)
		right_down(game);
	if (quad <= 0 || game->exit == 1)
	{
		game->exit = 0;
		fill_up(game);
	}
}
