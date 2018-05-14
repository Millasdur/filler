/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 11:34:42 by hlely             #+#    #+#             */
/*   Updated: 2018/05/14 11:26:09 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_horizon_weight(t_map *map, int y, int x, int inc)
{
	int		nb;
	int		inc_tmp;

	nb = 0;
	inc_tmp = inc;
	while (x + inc >= 0 && x + inc < map->xmax)
	{
		if (map->map[y][x + inc] != '.')
			return (nb);
		nb++;
		inc += inc_tmp;
	}
	return (nb);
}

static int	get_vertical_weight(t_map *map, int y, int x, int inc)
{
	int		nb;
	int		inc_tmp;

	nb = 0;
	inc_tmp = inc;
	while (y + inc >= 0 && y + inc < map->ymax)
	{
		if (map->map[y + inc][x] != '.')
			return (nb);
		nb++;
		inc += inc_tmp;
	}
	return (nb);
}

int			get_point_weight(t_map *map, int i, int j)
{
	int		weight;

	weight = 0;
	weight += get_vertical_weight(map, i, j, 1);
	weight += get_vertical_weight(map, i, j, -1);
	weight += get_horizon_weight(map, i, j, 1);
	weight += get_horizon_weight(map, i, j, -1);
	if (weight > map->best_weight)
		clean_n_store_point(map, i, j, weight);
	else if (weight == map->best_weight)
		store_point(map, i, j);
	return (weight);
}
