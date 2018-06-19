/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_board.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:23:59 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/19 08:12:05 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int in_board(int row, int col, t_fill *game)
{
	if (row < 0 || col < 0)
		return (0);
	else if (row > game->ROW(m_size) || col < game->COL(m_size))
		return (0);
	else
		return (1);
}
