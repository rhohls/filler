/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/16 11:29:52 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/16 15:35:03 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./filler.h"

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
//			filler.player.id = (line[10] == '1' ? 'O' : 'X');
			if (line[10] = '1')
				game->sym = 'O';//add opp piece			
			else if (line[10] = '2')
				game->sym = 'X';
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



