/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:48:09 by hlely             #+#    #+#             */
/*   Updated: 2018/05/13 13:45:27 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct			s_coord
{
	int			x;
	int			y;
}						t_coord;

typedef struct			s_map
{
	int			xmax;
	int			ymax;
	int			tx;
	int			ty;
	int			best_weight;
	int			best_x;
	int			best_y;
	int			x;
	int			y;
	char		c;
	char		e;
	char		**map;
	int			**weight;
	char		**tetri;
	t_list		*list;
	int			len;

}						t_map;

t_map					init_map(void);
int						get_map(t_map map);
t_map					fill_piece(t_map map);

int						put_piece(t_map *map);
int						get_point_weight(t_map *map, int i, int j);

void					get_best_move(t_map *map);
void					get_best_piece(t_map *map);
void					delete_weight_map(t_map *map);
void					delete_tetri(t_map *map);

void					show_map(t_map map);
void					show_tetri(t_map map);


#endif
