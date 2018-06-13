/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rhohls <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 09:39:43 by rhohls            #+#    #+#             */
/*   Updated: 2018/06/13 15:11:38 by rhohls           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define ROW(x) x[0]
# define COL(x) x[1]

typedef struct		s_fill
{
	char			**map;
	char			**piece;
	char			token;//my player piece
	int				m_size[2];
	int				p_size[2];
}					t_fill

#endif

