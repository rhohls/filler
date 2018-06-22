/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:29:52 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/18 15:23:14 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

/* 
** 0 is none intial
** 1 is map intial
** 2 is heatmap
** 3 is both
*/

void	get_game()
{
	int		line_num;
	char	*line;
	t_fill	*game;
	int		initial;
	int		piece_row;

	intial = 0;
	game = (t_fill)malloc(sizeof(t_fill));

	while (get_next_line(0, &line) == 1)
	{
		if (line[0] = '$') //initialize variable for heatmap and board
		{
			game->sym = (line[10] == '1' ? 'O' : 'X');
			game->op_sym[0] = (line[10] == '2' ? 'O' : 'X');
			game->op_sym[1] = ft_tolower(game->op_sym[0]);
		}
		else if (ft_strncmp(line, "Plateau", 7))
		{
			game->ROW(m_size) = ft_atoi(line[9]);
			game->ROW(m_size) = ft_atoi(line[9 + ft_nextdig(&line[9])]);
		}
		else if (ft_strncmp(line, "Piece", 5))
		{
			game->ROW(p_size) = ft_atoi(line[7]);
			game->ROW(p_size) = ft_atoi(line[7 + ft_nextdig(&line[7])]);
		}
		else if (ft_isdigit(line[0]))
		{
			if (intial < 1)
			{	
				gen_map(game);
				intial++;
			}
			game->map[ft_atoi(line)] = line + 3;
		}
		else if (line[0] == '*' || line[0] == '0')
		{
			get_piece(game);
			//then make descison where to place
			//then putchar placement
			free(game->piece);
			intial = 0;
		}
		free(line);
	}
}



