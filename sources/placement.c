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

#include "../includes/filler.h"

void	place_piece(t_fill *game)
{
	ft_putnbr(ROW(game->place) - game->ROW(trimmed));
	ft_putchar(' ');
	ft_putnbr(COL(game->place) - game->COL(trimmed));
	ft_putchar('\n');
	game->ROW(trimmed) = 0;
	game->COL(trimmed) = 0;
}

void	adj_place_vals(t_fill *game, int row, int col)
{
	game->ROW(place) = row;
	game->COL(place) = col;
}
