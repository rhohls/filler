/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_valid_move.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 07:23:46 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/14 08:19:42 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int valid_move(t_fill game, int *pos)
{
	//over map edge
	if ((ROW(pos) + game->ROW(p_size) + 1) > game->ROW(m_size))
		return (0);
	else if ((COL(pos) + game->COL(p_size) + 1) > game->COL(m_size))
		return (0);
	
	//only 1 piece overlap
	int row;
	int col;
	int valid;

	row = 0;
	valid = 2;

	while (row < ROW(p_size))
	{
		col = 0;
		while (col < COL(p_size))
		{
			//if cover a oppnent piece kill
			if (game->map[ROW(pos) + row][COL(pos) + col] == game->op_sym[1]
			|| game->map[ROW(pos) + row][COL(pos) + col] == game->op_sym[2])
				return (0);
			//if cover 1 pice reduce valid by 1
			if (game->map[ROW(pos) + row][COL(pos) + col] == game->token)
				valid--;
			if (valid < 1)
				return (0)
			col++;
		}
		row++;
	}

	if (valid == 1)
		return (1);
	else
		return (0);
}
