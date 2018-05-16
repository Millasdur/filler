/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:48:09 by hlely             #+#    #+#             */
/*   Updated: 2018/05/15 17:23:33 by hlely            ###   ########.fr       */
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
}						t_coord;

typedef struct			s_map
{
	int			xmax;
	int			ymax;
	int			tx;
	int			ty;
	int			best_weight;
	int			x;
	int			y;
	char		c;
	char		e;
	char		**map;
	int			**weight;
	char		**tetri;
	t_list		*list;
	t_list		*wl;
	int			len;

}						t_map;

t_map					init_map(void);
int						get_map(t_map map);
t_map					fill_piece(t_map map);

int						put_piece(t_map *map);
int						get_point_weight(t_map *map, int i, int j, int store);

void					calc_len(t_map *map, int y, int x, t_coord *point);
void					get_best_move(t_map *map);
void					get_best_piece(t_map *map);
void					delete_possibilities(t_list **list);
void					delete_tetri(t_map *map);

void					show_map(t_map map);
void					show_tetri(t_map map);


#endif
