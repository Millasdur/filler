/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_n_store_point.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 08:42:37 by hlely             #+#    #+#             */
/*   Updated: 2018/05/14 09:10:47 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		store_point(t_map *map, int i, int j)
{
	t_coord		point;

	point.x = i;
	point.y = j;
	ft_lstaddlast(&map->wl, ft_lstnew(&point, sizeof(t_coord)));
}

void		clean_n_store_point(t_map *map, int i, int j, int weight)
{
	map->best_weight = weight;
	delete_possibilities(&map->wl);
	store_point(map, i, j);
}
