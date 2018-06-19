/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printstate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 13:58:04 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/19 14:52:43 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"
#include <stdio.h>

void printstate(t_fill *game)
{
	int i = 0;
	printf("\n----------PRINTING GAME STATE---------\n");
	printf("\nMap:\n");
	while (i < game->ROW(m_size))
		printf("%s\n", game->map[i++]);
	
	i = 0;
	printf("\nPiece:\n");
	while (i < game->ROW(p_size))
		printf("%s\n", game->piece[i++]);

	printf("\nMy Symbol:\n");
	printf("%c\n", game->sym);

	printf("\nOpp Symbol:\n");
	printf("%c|%c\n", game->op_sym[0], game->op_sym[1]);

	printf("\nMapsize:\n");
	printf("Row:%i Col:%i\n", game->ROW(m_size), game->COL(m_size));
	
	printf("\nPiece size:\n");
	printf("Row:%i Col:%i\n", game->ROW(p_size), game->COL(p_size));

	printf("\nHeat map:\n");
	printf("none for now\n");

	printf("\nPlacement location:\n");
	printf("Row:%i Col:%i\n", game->ROW(place), game->COL(place));
}

