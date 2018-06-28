/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fil_add_heat.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 08:26:35 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/28 12:22:30 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

/*
** from top left of square add "heat units" in square shape
*/

static void apply_heat(int *start, int grd_size, int heat, t_fill *game)
{
	int row;
	int col;
	int row_work;
	int col_work;

	row = 0;
	while (row < grd_size)
	{
		row_work = ROW(start) + row - grd_size;
		col = 0;
		while (col < grd_size)
		{
			col_work = COL(start) + col - grd_size;
//			printf("fail at: %i, %i   grid size= %i\n",row,col,grd_size);
//			printf("board ref: %i %i \n", row_work, col_work);
//			printf("heat at |%i|\n",game->heat_map[ROW(start) + row][COL(start) + col]);
//			printf("succ\n");
			if (in_board(row_work, col_work, game))
				game->heat_map[row_work][col_work] += heat;
			col++;
		}
		row ++;
	}	
}

void add_heat_static(int row, int col, t_fill *game, int mult)
{
	int pos[2];

	pos[0] = row;
	pos[1] = col;
	add_heat(pos, game, mult);
}

void add_heat(int *pos, t_fill *game, int mult)
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
//	printf("while loop for :%i :%i\n",ROW(pos), COL(pos));
	while (loop > 0)
	{
		apply_heat(pos, grd_size, heat * mult, game);
		grd_size -= 2;
		loop--;
		heat++;
	}
/*	printf("addedheat at %i %i\n",ROW(pos), COL(pos));
	int j = 0;
	while (j < game->COL(m_size))
		printf("%d ",game->heat_map[8][j++]);
	printf("\t j=%i\n", j);
	*/
}

void remove_heat(t_fill *game)
{
	int row;
	int col;

	row = 0;
	while (row < game->ROW(m_size))
	{
		col = 0;
		while (col < game->COL(m_size))
		{
			if (game->map[row][col] == game->op_sym[0] ||
					game->map[row][col] == game->op_sym[1])
				game->heat_map[row][col] = 0;
			col++;
		}
		row++;
	}
}

	


