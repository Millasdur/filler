/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_weight.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/18 10:44:00 by hlely             #+#    #+#             */
/*   Updated: 2018/05/18 11:24:00 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	get_hori_weight(t_map *map, int y, int x, int inc)
{
	int		inctmp;
	int		weight;

	inctmp = inc;
	weight = 0;
	while (x + inc >= 0 && x + inc < map->ymax)
	{
		if (map->map[x + inc][y] != '.')
			return (weight);
		weight++;
		inc += inctmp;
	}
	return (weight);
}

static int	get_vert_weight(t_map *map, int y, int x, int inc)
{
	int		inctmp;
	int		weight;

	inctmp = inc;
	weight = 0;
	while (y + inc >= 0 && y + inc < map->xmax)
	{
		if (map->map[x][y + inc] != '.')
			return (weight);
		weight++;
		inc += inctmp;
	}
	return (weight);
}

int			get_weight(t_map *map, int y, int x)
{
	int		weight;

	weight = get_vert_weight(map, x, y, 1);
	weight += get_vert_weight(map, x, y, -1);
	weight += get_hori_weight(map, x, y, 1);
	weight += get_hori_weight(map, x, y, -1);
	return (weight);
}
