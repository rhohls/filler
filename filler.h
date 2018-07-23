/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:39:43 by rhohls            #+#    #+#             */
/*   Updated: 2018/07/02 14:18:12 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define ROW(x) x[0]
# define COL(x) x[1]

#include <stdlib.h>
#include "./includes/libft.h"
#include "./includes/get_next_line.h"
#include <stdio.h>

typedef struct		s_fill
{
	char			**map;
	char            **old_map;
	char			**piece;
	char			sym;//my player piece
	char			op_sym[2];
	int				m_size[2];
	int				p_size[2];
	int				**heat_map;
	int				place[2];
	int				initial;
	int				trimmed[2];
	int 			exit;
	int				top;
}					t_fill;

void	adj_place_vals(t_fill *game, int row, int col);

void    gen_heatmap(t_fill *game);
void    gen_map(t_fill *game);
void	copy_game_map(t_fill *game);

int		op_quadrant(t_fill *game);
int			*op_location(t_fill *game);

void    get_piece(t_fill *game, char *line, int fd);

int		valid_move(t_fill *game, int *pos);
void    place_piece(t_fill *game);
void 	decide(t_fill *game);
int		valid_move_static(t_fill *game, int rowin, int colin);
t_fill	*play_game(int fd);
int		in_board(int row, int col, t_fill *game);
void	printstate(t_fill *game, int fd);

void	trim_piece(t_fill *game);
void	trim_right(t_fill *game, int row, int col);
void	trim_left(t_fill *game, int row, int col);

void	add_heat_static(int row, int col, t_fill *game, int mult);
void	add_heat(int *pos, t_fill *game, int mult);
void	reset_heat(t_fill *game);

void	edge_heat(t_fill *game);
void	remove_heat(t_fill *game);
void    place_basic(t_fill *game);
void	place_smallmap(t_fill *game);
void    fill_up(t_fill *game);

int		right_up_complex(t_fill *game, int curr_row, int curr_col);
int     left_up_complex(t_fill *game, int curr_row, int curr_col);
int     left_down_complex(t_fill *game, int curr_row, int curr_col);
int     right_down_complex(t_fill *game, int curr_row, int curr_col);

#endif

