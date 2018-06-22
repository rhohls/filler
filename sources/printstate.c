/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:58:04 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/22 14:31:32 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include <stdio.h>

void printstate(t_fill *game,int fd)
{
	int i = 0;
	dprintf(fd, "\n----------PRINTING GAME STATE---------\n");
	dprintf(fd, "\nMap:\n");
	while (i < game->ROW(m_size))
		dprintf(fd, "%s\n", game->map[i++]);
	
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

	dprintf(fd, "\nHeat map:\n");
	dprintf(fd, "none for now\n");

	dprintf(fd, "\nPlacement location:\n");
	dprintf(fd, "Row:%i Col:%i\n", game->ROW(place), game->COL(place));
}

