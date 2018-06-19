/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tes123.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 07:27:49 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/19 07:34:21 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	t_fill	*game;
	game = (t_fill *)malloc(sizeof(t_fill));

	game->place[0] = 3;
	game->place[1] = 5;

	game->ROW(place) = 13;
	game->COL(place) = 15;

	printf("0: %i 1: %i \n", game->ROW(place), game->COL(place));

	return 1;
}


