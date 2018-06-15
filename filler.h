/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:39:43 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/14 08:21:24 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define ROW(x) x[0]
# define COL(x) x[1]
# define OP_TOK(x) 

typedef struct		s_fill
{
	char			**map;
	char			**piece;
	char			sym;//my player piece
	char			op_sym[2];
	int				m_size[2];
	int				p_size[2];
}					t_fill

int valid_move(t_fill game, int *pos);

#endif

