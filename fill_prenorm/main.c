/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openread.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 06:53:37 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/25 07:43:31 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include <strings.h>
#include <fcntl.h>
#include "filler.h"

int main()
{
	t_fill	*game;

	while (1)
	{
        game = play_game(0);
		if (game->exit)
			break ;
	}
	return (1);
}

