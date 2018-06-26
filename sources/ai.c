/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/26 11:20:38 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/26 13:36:59 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static void partners(t_fill *game, int row, int col)
{
	int amount;
	
	amount = 0;

	if (game->map[row][col + 1] == game->op_sym[0] ||
		   game->map[row][col + 1] == game->op_sym[1])
		amount++;
}	


	


void edge_head(t_fill *game)
{
	int row;
	int col;

	row = 1;
	while (row < game->ROW(p_size) - 1)
	{
		col = 1;
		while (col < game->COL(p_size) - 1)
		{
			if (game->piece[0][col] == '*')
				return ;
			col--;
		}
		row--;
	}
}



