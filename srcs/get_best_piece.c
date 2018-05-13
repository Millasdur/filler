/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:12:04 by hlely             #+#    #+#             */
/*   Updated: 2018/05/13 13:02:45 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		get_best_piece(t_map *map)
{
	int		len;
	t_list	*tmp;
	t_coord	*coord;

	len = -1;
	tmp = map->list;
	while (tmp)
	{
		coord = (t_coord*)tmp->content;
	/* ft_dprintf(2, "[%d] - [%d] + [%d] - [%d]\n", map->best_x, coord->x, map->best_y, coord->y); */
		len = ft_power(map->best_x - coord->x, 2) +
			ft_power(map->best_y - coord->y, 2);
	/* ft_dprintf(2, "len : [%d]\n", len); */
		if (map->len == -1 || len < map->len)
		{
			map->x = coord->x;
			map->y = coord->y;
			map->len = len;
	/* ft_dprintf(2, "Best Piece : [%d][%d]\n", map->x, map->y); */
		}
		tmp = tmp->next;
	}
}
