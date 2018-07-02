/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 14:44:41 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/02 09:50:44 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

/*
**	see bottom for direction decision 
*/

static void	right_up(t_fill *game)
{
	int row;
	int col;

	row = 0;
	while (row < (game->ROW(m_size) / 2))
	{
		col = game->COL(m_size) / 2;
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
		row++;
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
	while (row < (game->ROW(m_size) / 2))
	{
		col = 0;
		while (col < (game->COL(m_size) / 2))
		{
			if (valid_move_static(game, row, col))
			{
				game->ROW(place) = row - game->ROW(trimmed);
				game->COL(place) = col - game->COL(trimmed);
				return ;
			}
			col++;
		}
		row++;
	}
	game->ROW(place) = 0;
	game->COL(place) = 0;
	game->exit = 1;
}

static void	left_down(t_fill *game)
{
	int row;
	int col;

	row = game->ROW(m_size) / 2;
	while (row >= 0)
	{
		col = 0;
		while (col < (game->COL(m_size) / 2))
		{
			if (valid_move_static(game, row, col))
			{
				game->ROW(place) = row - game->ROW(trimmed);
				game->COL(place) = col - game->COL(trimmed);
				return ;
			}
			col++;
		}
		row--;
	}
	game->ROW(place) = 0;
	game->COL(place) = 0;
	game->exit = 1;
}

static void	right_down(t_fill *game)
{
	int row;
	int col;

	row = game->ROW(m_size) / 2;
	while (row >= 0)
	{
		col = game->COL(m_size) / 2;
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

void	place_basic(t_fill *game)
{
	int quad;

	quad = op_location(game);
	fprintf(stderr, "~~~---- %i %i %i -----~~~\n",quad,quad,quad);
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

