/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:03:31 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/22 15:08:56 by rhohls           ###   ########.fr       */
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
/*
void	place_piece(t_fill *game)
{
	printf("%i %i\n", ROW(game->place), COL(game->place));
}
*/
/*
** -1 for row and col if no valid move
*/
void decide(t_fill *game)
{
	int row;
	int col;

	row = 0;

	while (row < game->ROW(m_size))
	{
		col = 0;
		while (col < game->COL(m_size))
		{
			if (valid_move_static(game, row, col))
			{
				game->ROW(place) = row;
				game->COL(place) = col;
				return ;
			}
			col++;
		}
		row++;
	}
	game->ROW(place) = 0;
	game->COL(place) = 0;
}
			
