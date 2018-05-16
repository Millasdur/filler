/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:10:16 by hlely             #+#    #+#             */
/*   Updated: 2018/05/15 18:45:00 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	tiny_loop(t_map *map, int y, int x, t_coord *point)
{
	int		k;
	int		l;
	int		len;

	k = 0;
	while (k < map->ymax)
	{
		l = 0;
		while (l < map->xmax)
		{
			if (map->map[k][l] == map->e)
			{
				if (point->len == -1)
					point->len = ft_pow(k - y, 2) + ft_pow(l - x, 2);
				else if ((len = ft_pow(k - y, 2) +
							ft_pow(l - x, 2)) < point->len)
					point->len = len;
			}
			l++;
		}
		k++;
	}
}

void		calc_len(t_map *map, int y, int x, t_coord *point)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->ty)
	{
		j = 0;
		while (j < map->tx)
		{
			if (map->tetri[i][j] == '*')
			{
				tiny_loop(map, y + i, x + j, point);
			}
				j++;
		}
		i++;
	}
}

void		get_best_move(t_map *map)
{
	t_list		*tmp;
	t_coord		*point;

	tmp = map->list;
	while (tmp)
	{
		point = (t_coord*)tmp->content;
		if (map->len == -1
				|| point->len < map->len)
		{
			map->x = point->x;
			map->y = point->y;
			map->len = point->len;
		}
		tmp = tmp->next;
	}
}
