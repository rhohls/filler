/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:39:43 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/22 14:34:56 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define ROW(x) x[0]
# define COL(x) x[1]
# define OP_TOK(x) 

#include <stdlib.h>
#include "./includes/libft.h"
#include "./includes/get_next_line.h"
#include <stdio.h>

typedef struct		s_fill
{
	char			**map;
	char			**piece;
	char			sym;//my player piece
	char			op_sym[2];
	int				m_size[2];
	int				p_size[2];
	int				**heat_map;
	int				place[2];
	int				initial;
}					t_fill;

void    gen_heatmap(t_fill *game);
void    gen_map(t_fill *game);
void    gen_piece(t_fill *game);
void    get_piece(t_fill *game, char *line, int fd);
int		valid_move(t_fill *game, int *pos);
void    place_piece(t_fill *game);
void 	decide(t_fill *game);
int		valid_move_static(t_fill *game, int rowin, int colin);
t_fill	*play_game(int fd);
int		in_board(int row, int col, t_fill *game);
void	 printstate(t_fill *game, int fd);
#endif

