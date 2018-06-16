/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_add_heat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:26:35 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/16 11:27:08 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
** from top left of square add "heat units" in square shape
*/

void apply_heat(int *start, int grd_size, int heat, t_fill game)
{
	int row;
	int col;

	row = 0;
	while (row < grd_size)
	{
		col = 0;
		while (col < grd_size)
		{
			if (in_board(ROW(start) + row, COL(start) + col, t_fill game))
				game->heat_map[ROW(start) + row][COL(start) + col] += heat;
			col++;
		}
		row ++;
	}	
}

void add_heat(int *pos, t_fill game, int mult)
{
	int grd_size;
	int loop;
	int heat;

	grd_size = 7;
	loop = 3;
	heat = 1;
	
	if (in_board(ROW(pos), COL(pos), game))
		game->heat_map[ROW(pos)][COL(pos)] += 4 * mult;
	else
		return ;
	while (loop > 0)
	{
		apply_heat(pos, grd_size, heat * mult, game);
		grd_size -= 2;
		loop--;
		heat++;
	}
}



	






