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
#include "./includes/filler.h"

int main()
{
	static t_fill	*game;
	char			*line;
	
	game = (t_fill *)malloc(sizeof(t_fill));
	game->initial = 0;
	game->exit = 0;
	game->top = 1;
	line = NULL;

	if (get_next_line(0, &line) != 1)
		return (0);
	if (line[0] == '$')
	{
		game->sym = (line[10] == '1' ? 'O' : 'X');
		game->op_sym[0] = (line[10] == '2' ? 'O' : 'X');
		game->op_sym[1] = ft_tolower(game->op_sym[0]);
	}
	while (1)
	{
        game = play_game(0, game);
		if (game->exit)
			break ;
	}
	return (1);
}

