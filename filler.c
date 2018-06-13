/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 13:11:55 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/13 15:19:59 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int valid_move(t_fill game, int *placement)
{
	//over map edge
	if ((ROW(placement) + game->ROW(p_size) + 1) > game->ROW(m_size))
		return (0);
	else if ((COL(placement) + game->COL(p_size) + 1) > game->COL(m_size))
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
			//if cover 1 pice reduce valid by 1
			col++;
		}
		row++;
	}

	//if valid == 1 then good else bad
			






