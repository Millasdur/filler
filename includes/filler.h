/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:48:09 by hlely             #+#    #+#             */
/*   Updated: 2018/05/19 12:27:48 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct			s_coord
{
	int			x;
	int			y;
	int			len;
	int			wei;
}						t_coord;

typedef struct			s_map
{
	int			xmax;
	int			ymax;
	int			tx;
	int			ty;
	int			ntx;
	int			nty;
	int			dx;
	int			dy;
	int			wei;
	int			x;
	int			y;
	char		c;
	char		e;
	char		**map;
	char		**tetri;
	t_list		*list;
	int			len;

}						t_map;

t_map					init_map(void);
int						get_map(t_map *map);
int						fill_piece(t_map *map);

int						put_piece(t_map *map);

int						only_horiz_dot(t_map *map, int y);
int						only_vert_dot(t_map *map, int x);
int						get_weight(t_map *map, int y, int x);

void					calc_len(t_map *map, int y, int x, t_coord *point);
void					get_best_move(t_map *map);
void					delete_possibilities(t_list **list);
void					delete_tetri(t_map *map);
void					delete_map(t_map *map);

#endif
