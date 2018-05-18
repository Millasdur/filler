/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   only_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/17 11:26:27 by hlely             #+#    #+#             */
/*   Updated: 2018/05/18 14:22:32 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		only_horiz_dot(t_map *map, int y)
{
	int		i;

	i = 0;
	while (map->tetri[y][i])
	{
		if (map->tetri[y][i] != '.')
			return (0);
		i++;
	}
	return (1);
}

int		only_vert_dot(t_map *map, int x)
{
	int		i;

	i = 0;
	while (i < map->ty)
	{
		if (map->tetri[i][x] != '.')
			return (0);
		i++;
	}
	return (1);
}
