/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:21:43 by hlely             #+#    #+#             */
/*   Updated: 2018/05/19 13:22:00 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		delete_map(t_map *map)
{
	int		i;

	i = 0;
	if (map->map)
	{
		while (i < map->ymax)
		{
			ft_strdel(&map->map[i]);
			i++;
		}
		free(map->map);
		map->map = NULL;
	}
}

void		delete_tetri(t_map *map)
{
	int		i;

	i = 0;
	if (map->tetri)
	{
		while (i < map->ty)
		{
			ft_strdel(&map->tetri[i]);
			i++;
		}
		free(map->tetri);
		map->tetri = NULL;
	}
	map->tx = -1;
	map->ty = -1;
	map->ntx = 0;
	map->nty = 0;
}

void		delete_possibilities(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		if (tmp->content)
			free(tmp->content);
		if (tmp)
			free(tmp);
	}
	*list = NULL;
}
