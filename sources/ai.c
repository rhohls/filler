/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:20:38 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/27 15:41:03 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int partners(t_fill *game, int row, int col)
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
	
	if (amount == 4)
		return (0);
	return (amount);
}	

void edge_heat(t_fill *game)
{
	printf("__edgeheat\n");
	int row;
	int col;

	row = 1;
	while (row < game->ROW(m_size) - 1)
	{
		col = 1;
		while (col < game->COL(m_size) - 1)
		{
			//printf("part %i row %i col %i", partners(game, row, col), row, col);
			if (partners(game, row, col) > 0)
			{
				printf("\n123123\n\n");
				add_heat_static(row, col, game, 1);
			}
			col++;
		}
		row++;
	}
}



