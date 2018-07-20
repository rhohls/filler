/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location_decision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 07:54:51 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/06 07:56:47 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

/*
** To improve code
** 1. Add "conditions" for stop start and incriment
** for each quadrant
** 2. Simplifiy code to use these conditions
*/

/*
** To improve game
** Have more heatmap usage
** 1. Where player last went
** 2. near edge of board
** 3. Try cut off horizontal/vertical
*/

/*
** ht_mp_prop:
** 0: heatmap val  1,2: row,col
*/

int		highest_map(t_fill *game, int *ht_mp_prop)
{
	int row;
	int col;

//	dprintf(2, "in highest_map\n");
	row = 0;
	while (row < game->ROW(m_size))
	{
		col = 0;
		//dprintf(2, "on row :%i\n",row);
		while (col < game->COL(m_size))
		{
			//dprintf(2, "checking for highest heat on row:%i, col:%i \n",row, col);
		//	dprintf(2, "actual heat at row:%i, col:%i -- %i\n",row, col, game->heat_map[row][col]);
			if (game->heat_map[row][col] >= ht_mp_prop[0])
			{
				ht_mp_prop[0] = game->heat_map[row][col];
				ht_mp_prop[1] = row;
				ht_mp_prop[2] = col;
			}
			col++;
		}
		row++;
	}
	return (ht_mp_prop[0]);
}

void	fill_up(t_fill *game)
{
	int row;
	int col;

	row = game->ROW(m_size);
	while (row >= 0)
	{
		col = game->COL(m_size);
		while (col >= 0)
		{
//			dprintf(2, "move result from row %i, col %i   result: %i", row, col, valid_move_static(game, row, col));
			if (valid_move_static(game, row, col))
			{
				game->ROW(place) = row;// - game->ROW(trimmed);
				game->COL(place) = col;// - game->COL(trimmed);
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

void	decide(t_fill *game)
{
	int ht_mp_prop[3];
	ht_mp_prop[0] = 0;
	ht_mp_prop[1] = 0;
	ht_mp_prop[2] = 0;
//	ft_putstr_fd("in decide\n",2);
	while (highest_map(game, ht_mp_prop) > 0)
	{
		game->heat_map[ht_mp_prop[1]][ht_mp_prop[2]] = 0;
		ht_mp_prop[0] = 0;
	//	dprintf(2,"##checking valid move from heat map for row:%i col:%i\n", ht_mp_prop[1], ht_mp_prop[2]);
	//	dprintf(2, "above valid\n"); 
		if (valid_move_static(game, ht_mp_prop[1], ht_mp_prop[2]))
		{
			game->ROW(place) = ht_mp_prop[1];
			game->COL(place) = ht_mp_prop[2];
			return ;
		}
	}
//	ft_putstr_fd("now playing basic\n",2);
	place_basic(game);
}
