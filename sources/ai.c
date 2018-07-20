/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:20:38 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/03 06:55:51 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int	own_piece(t_fill *game, int row, int col)
{
	int amount;

	amount = 0;
	if (game->map[row][col + 1] == game->sym)
		amount++;
	if (game->map[row][col - 1] == game->sym)
		amount++;
	if (game->map[row + 1][col] == game->sym)
		amount++;
	if (game->map[row - 1][col] == game->sym)
		amount++;
	if (amount >= 4)
		return (4);
	return (amount);
}

static int	opp_piece(t_fill *game, int row, int col)
{
	int amount;

	amount = 0;
	if (game->map[row][col + 1] == game->op_sym[0] ||
			game->map[row][col + 1] == game->op_sym[1])
		amount++;
	if (game->map[row][col - 1] == game->op_sym[0] ||
			game->map[row][col - 1] == game->op_sym[1])
		amount++;
	if (game->map[row + 1][col] == game->op_sym[0] ||
			game->map[row + 1][col] == game->op_sym[1])
		amount++;
	if (game->map[row - 1][col] == game->op_sym[0] ||
			game->map[row - 1][col] == game->op_sym[1])
		amount++;
	if (amount > 0)
		amount += own_piece(game, row, col);
	if (amount >= 4)
		return (0);
	return (amount);
}

void		edge_heat(t_fill *game)
{
	int row;
	int col;

	row = 1;
	while (row < game->ROW(m_size) - 1)
	{
		col = 1;
		while (col < game->COL(m_size) - 1)
		{
			if (opp_piece(game, row, col) > 0)
				add_heat_static(row, col, game, 1);
			col++;
		}
		row++;
	}
	remove_heat(game);
}
