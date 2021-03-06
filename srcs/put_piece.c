/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 21:47:24 by hlely             #+#    #+#             */
/*   Updated: 2018/05/21 08:59:02 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		can_put(t_map *map, char **tetri, int y, int x)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	nb = 0;
	while (i < map->ty - map->dy)
	{
		j = 0;
		while (j < map->tx - map->dx)
		{
			if (tetri[i][j] == '*')
			{
				if (map->map[y + i][x + j] != '.' &&
						map->map[y + i][x + j] != map->c)
					return (0);
				if (map->map[y + i][x + j] != '.' &&
						map->map[y + i][x + j] == map->c)
					nb++;
			}
			j++;
		}
		i++;
	}
	return (nb == 1 ? 1 : 0);
}

t_coord			new_point(t_map *map, int i, int j)
{
	t_coord		point;

	point.len = -1;
	calc_len(map, i, j, &point);
	point.x = i;
	point.y = j;
	point.wei = -1;
	return (point);
}

static int		get_posable_list(t_map *map, char **tetri)
{
	int			i;
	int			j;
	int			nb;
	t_coord		point;

	i = 0;
	nb = 0;
	while (i < map->ymax - map->nty + 1)
	{
		j = 0;
		while (j < map->xmax - map->ntx + 1)
		{
			if (can_put(map, tetri, i, j))
			{
				point = new_point(map, i, j);
				ft_lstaddlast(&map->list,
						ft_lstnew(&point, sizeof(t_coord)));
				nb++;
			}
			j++;
		}
		i++;
	}
	return (nb);
}

int				put_piece(t_map *map)
{
	int		nb;

	nb = get_posable_list(map, map->tetri);
	if (nb == 0)
		return (0);
	get_best_move(map);
	ft_printf("%d %d\n", map->x - map->dy, map->y - map->dx);
	delete_possibilities(&map->list);
	delete_tetri(map);
	return (1);
}
