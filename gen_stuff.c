/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_stuff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 14:33:00 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/18 14:33:38 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

// add protection -- run in while loop till malloc returns
void	gen_heatmap(t_fill game)
{	
	game->heat_map = (int **)malloc(sizeof(int *) * ROW(m_size));
	int	count = 0;
	while (count < ROW(m_size))
	{
		game->heat_map[count] = (int *)malloc(sizeof(int) * COL(m_size));
		count++;
	}
}

void	gen_map(t_fill game)
{	
	game->map = (char **)malloc(sizeof(char *) * ROW(m_size));
	int	count = 0;
	while (count < ROW(m_size))
	{
		game->heat_map[count] = (char *)malloc(sizeof(char) * COL(m_size));
		count++;
	}
}

void	gen_piece(t_fill game)
{	
	game->piece = (char **)malloc(sizeof(char *) * ROW(p_size));
	int	count = 0;
	while (count < ROW(p_size))
	{
		game->piece[count] = (char *)malloc(sizeof(char) * COL(p_size));
		count++;
	}
}

void	get_piece(t_fill game)
{
	int		i;
	char	*line;

	i = 0;
	gen_piece(game);
	while (i < game->ROW(p_size) && get_next_line(0, &line))
	{
		game->ROW(piece) = line;
		free(line);
		i++;
	}
}
