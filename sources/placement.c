/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:03:31 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/26 11:51:27 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include <stdio.h>

void	place_piece(t_fill *game)
{
	ft_putnbr(ROW(game->place));
	ft_putchar(' ');
	ft_putnbr(COL(game->place));
	ft_putchar('\n');

	ft_putnbr_fd(ROW(game->place), 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(COL(game->place), 2);
	ft_putchar_fd('\n', 2);
}

//go diag in direction???? for start
//go from bottom up for end


/*
** 0 for row and col if no valid move and exit
** goes fom bottom up (will auto fill) 
*/
void decide(t_fill *game)
{
	int row;
	int col;

	row = game->ROW(m_size) - 0;

	while (row >= 0)
	{
		col = game->COL(m_size) - 0;
		while (col >= 0)
		{
			if (valid_move_static(game, row, col))
			{
				game->ROW(place) = row - game->ROW(trimmed);
				game->COL(place) = col - game->COL(trimmed);
				game->ROW(trimmed) = 0;
				game->COL(trimmed) = 0;
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
			
