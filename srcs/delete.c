/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 17:21:43 by hlely             #+#    #+#             */
/*   Updated: 2018/05/15 17:42:54 by hlely            ###   ########.fr       */
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
	map->tx = -1;
	map->ty = -1;
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
