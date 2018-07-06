/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   placement.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:03:31 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/06 07:56:49 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	place_piece(t_fill *game)
{
	ft_putnbr(ROW(game->place));
	ft_putchar(' ');
	ft_putnbr(COL(game->place));
	ft_putchar('\n');
	game->ROW(trimmed) = 0;
	game->COL(trimmed) = 0;
}

void	place_trim(t_fill *game, int row, int col)
{
	game->ROW(place) = row - game->ROW(trimmed);
	game->COL(place) = col - game->COL(trimmed);
}
