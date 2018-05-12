/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:48:09 by hlely             #+#    #+#             */
/*   Updated: 2018/05/12 22:54:57 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

<<<<<<< HEAD
typedef struct			s_coord
{
	int			x;
	int			y;
}						t_coord;
=======
typedef struct			s_tetri
{
	int			xmax;
	int			ymax;
	char		**shape;
}						t_tetri;
>>>>>>> 1089c14ab2f6b2c851c8d021a46f718bebdff509

typedef struct			s_map
{
	int			xmax;
	int			ymax;
	int			tx;
	int			ty;
	char		c;
	char		**map;
<<<<<<< HEAD
	int			**weight;
	char		**tetri;
	t_list		*list;
=======
	int			len;
	t_tetri		tetri;
>>>>>>> 1089c14ab2f6b2c851c8d021a46f718bebdff509

}						t_map;

t_map					init_map(void);
<<<<<<< HEAD
int						get_map(t_map map);
t_map					fill_piece(t_map map);

int						put_piece(t_map *map);

void					show_map(t_map map);
void					show_tetri(t_map map);
=======
t_map					get_map(t_map map);
t_map					putpart(t_map map);
t_tetri					parse_tetri(void);

>>>>>>> 1089c14ab2f6b2c851c8d021a46f718bebdff509

#endif
