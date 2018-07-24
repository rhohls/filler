/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:58:04 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/06 11:47:23 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <stdio.h>
#include <unistd.h>

void	mini_for(void)
{
	int i;

	i = 0;
	while (i < 1000)
		i++;
}

void	printstate(t_fill *game, int fd)
{
	int i;
	int j;

	i = 0;
	j = 0;

	dprintf(fd, "\n----------PRINTING GAME STATE---------\n");
	dprintf(fd, "\nMap:\n");
	while (i < game->ROW(m_size))
	{
		dprintf(fd, "%s\t%p\n", game->map[i], game->map[i]);
		i++;
	}

	dprintf(fd, "\nOld_Map:\n");
	if (!game->map)
		dprintf(fd, "None\n");
	else
	{
		i = 0;
		while (i < game->ROW(m_size))
		{
			dprintf(fd, "%s\t%p\n", game->map[i], game->map[i]);
			i++;
		}
	}

	i = 0;
	dprintf(fd, "\nHeat map:\n");
	while (i < game->ROW(m_size))
	{
		j = 0;
		while (j < game->COL(m_size))
		{
			dprintf(fd, "%d ", game->heat_map[i][j]);
			if (game->heat_map[i][j] < 10)
				dprintf(fd, " ");
			j++;
		}
		dprintf(fd, "\n");
		i++;
	}

	i = 0;
	dprintf(fd, "\nPiece:\n");
	while (i < game->ROW(p_size))
		dprintf(fd, "%s\n", game->piece[i++]);

	dprintf(fd, "\nMy Symbol:\n");
	dprintf(fd, "%c\n", game->sym);

	dprintf(fd, "\nOpp Symbol:\n");
	dprintf(fd, "%c|%c\n", game->op_sym[0], game->op_sym[1]);

	dprintf(fd, "\nMapsize:\n");
	dprintf(fd, "Row:%i Col:%i\n", game->ROW(m_size), game->COL(m_size));

	dprintf(fd, "\nPiece size:\n");
	dprintf(fd, "Row:%i Col:%i\n", game->ROW(p_size), game->COL(p_size));

	dprintf(fd, "\nPlacement offset:\n");
	dprintf(fd, "Row:%i Col:%i\n", game->ROW(trimmed), game->COL(trimmed));

	dprintf(fd, "\nPlacement location:\n");
	dprintf(fd, "Row:%i Col:%i\n", game->ROW(place) - game->ROW(trimmed),
									game->COL(place) - game->COL(trimmed));

	mini_for();
}
