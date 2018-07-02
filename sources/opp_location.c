/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_location.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/29 07:03:12 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/02 09:39:50 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

static int quadrant(t_fill *game, int row, int col)
{
	if (col >= (game->COL(m_size) / 2) && row >= (game->ROW(m_size) / 2))
		return (4);
	else if (col >= (game->COL(m_size) / 2) && row < (game->ROW(m_size) / 2))
		return (1);
	else if (col < (game->COL(m_size) / 2) && row < (game->ROW(m_size) / 2))
		return (2);
	else if (col < (game->COL(m_size) / 2) && row >= (game->ROW(m_size) / 2))
		return (3);
	return (0);
}

int op_location(t_fill *game)
{
	int row;
	int col;
	
	fprintf(stderr," add %p\n",game->old_map);
	row = 0;
	while (row < game->ROW(m_size))
	{
		dprintf(2,"oldmap %p  newmap %p\n",game->old_map[row],game->map[row] );
		col = 0;
		while (col < game->COL(m_size))
		{
			
			dprintf(2, "row: %i, col: %i---\tsymbol: %c opp_sym: %c RESULT |%i|\n",
					row, col, game->map[row][col], game->op_sym[1], 
					game->map[row][col] == game->op_sym[1]);
			if ((game->old_map) && (game->map[row][col] == game->op_sym[0]) &&
					(game->map[row][col] != game->old_map[row][col]))
			{
				return (quadrant(game, row, col));
			}
			col++;
		}
		row++;
	}
	return (-1);
}
