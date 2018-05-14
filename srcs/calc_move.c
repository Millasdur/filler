/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:11:19 by hlely             #+#    #+#             */
/*   Updated: 2018/05/14 13:34:42 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		delete_tetri(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->ty)
	{
		free(map->tetri[i]);
		map->tetri[i] = NULL;
		i++;
	}
}

void		print_map_weight(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->ymax)
	{
		j = 0;
		ft_dprintf(2, "[%2d] ", i);
		while (j < map->xmax)
		{
			ft_dprintf(2, "%d.", map->weight[i][j]);
			j++;
		}
		ft_dprintf(2, "\n");
		i++;
	}
		ft_dprintf(2, "\n");
}

void		delete_weight_map(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->ymax)
	{
		free(map->weight[i]);
		i++;
	}
	map->best_weight = 0;
	map->x = 0;
	map->y = 0;
	map->len = -1;
}

void		get_map_weight(t_map *map)
{
	int		i;
	int		j;

	if (!map->weight)
		map->weight = ft_memalloc(sizeof(int*) * (map->ymax));
	i = 0;
	while (i < map->ymax)
	{
		j = 0;
		map->weight[i] = ft_memalloc(sizeof(int) * (map->xmax));
		while (j < map->xmax)
		{
			if (map->map[i][j] == map->e)
				map->weight[i][j] = get_point_weight(map, i, j);
			else
				map->weight[i][j] = 0;
			j++;
		}
		i++;
	}
}

void		get_best_move(t_map *map)
{
	get_map_weight(map);
	get_best_piece(map);
	/* print_map_weight(map); */
}
