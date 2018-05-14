/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_piece.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/13 12:12:04 by hlely             #+#    #+#             */
/*   Updated: 2018/05/14 17:59:09 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/* static int	hori_contact(t_map *map, int y, int x, int inc) */
/* { */
/* 	int		nb; */
/* 	int		inc_tmp; */

/* 	nb = 0; */
/* 	inc_tmp = inc; */
/* 	if (x + inc >= 0 && x + inc < map->xmax) */
/* 	{ */
/* 		if (map->map[y][x + inc] == map->e) */
/* 			return (1); */
/* 	} */
/* 	return (0); */
/* } */

/* static int	vert_contact(t_map *map, int y, int x, int inc) */
/* { */
/* 	int		nb; */
/* 	int		inc_tmp; */

/* 	nb = 0; */
/* 	inc_tmp = inc; */
/* 	if (y + inc >= 0 && y + inc < map->ymax) */
/* 	{ */
/* 		if (map->map[y + inc][x] == map->e) */
/* 			return (1); */
/* 	} */
/* 	return (0); */
/* } */

/* static int	has_contact(t_map *map, t_coord  *pos) */
/* { */
/* 	int		i; */
/* 	int		j; */

/* 	i = 0; */
/* 	while (i < map->ty) */
/* 	{ */
/* 		j = 0; */
/* 		while (j < map->tx) */
/* 		{ */
/* 			if (map->tetri[i][j] == '*' */
/* 					&& (vert_contact(map, pos->x + i, pos->y + j, 1) */
/* 					|| vert_contact(map, pos->x + i, pos->y + j, -1) */
/* 					|| hori_contact(map, pos->x + i, pos->y + j, 1) */
/* 					|| hori_contact(map, pos->x + i, pos->y + j, -1))) */
/* 			{ */
/* 				ft_dprintf(2, "CONTACT"); */
/* 				return (1); */
/* 			} */
/* 			j++; */
/* 		} */
/* 		i++; */
/* 	} */
/* 	return (0); */
/* } */


/* static int	can_go(t_map *map, t_coord *pos, t_coord *coord) */
/* { */
/* 	int		x; */
/* 	int		y; */
/* 	int		i; */
/* 	int		j; */
/* 	int		nb; */

/* 	nb = 0; */
/* 	i = 0; */
/* 	j = 0; */
/* 	x = coord->x - pos->x < 0 ? -1 : 1; */
/* 	y = coord->y - pos->y < 0 ? -1 : 1; */
/* 	while (pos->x + i != coord->x) */
/* 	{ */
/* 		if (map->map[pos->x + i][pos->y + j] != '.') */
/* 			nb++; */
/* 		i += x; */
/* 	} */
/* 	return (nb); */
/* } */

static int	get_horizon_weight(t_map *map, int y, int x, int inc)
{
	int		inc_tmp;

	inc_tmp = inc;
	while (x + inc >= 0 && x + inc < map->xmax)
	{
		if (map->map[y][x + inc] != map->e)
			return (0);
		inc += inc_tmp;
	}
	return (1);
}

static int	get_vertical_weight(t_map *map, int y, int x, int inc)
{
	int		inc_tmp;

	inc_tmp = inc;
	while (y + inc >= 0 && y + inc < map->ymax)
	{
		if (map->map[y + inc][x] == map->e)
			return (0);
		inc += inc_tmp;
	}
	return (1);
}

static int	is_free(t_map *map, t_coord *pos)
{
	int		nb;

	nb = get_vertical_weight(map, pos->x, pos->y, 1);
	nb += get_vertical_weight(map, pos->x, pos->y, -1);
	nb += get_horizon_weight(map, pos->x, pos->y, 1);
	nb += get_horizon_weight(map, pos->x, pos->y, -1);
	return (nb);
}

static int	get_horizon_danger(t_map *map, int y, int x, int inc)
{
	int		inc_tmp;

	inc_tmp = inc;
	while (x + inc >= 0 && x + inc < map->xmax)
	{
		if (map->map[y][x + inc] != map->c)
			return (0);
		inc += inc_tmp;
	}
	return (1);
}

static int	get_vertical_danger(t_map *map, int y, int x, int inc)
{
	int		inc_tmp;

	inc_tmp = inc;
	while (y + inc >= 0 && y + inc < map->ymax)
	{
		if (map->map[y + inc][x] == map->c)
			return (0);
		inc += inc_tmp;
	}
	return (1);
}

static int	is_danger(t_map *map, t_coord *pos)
{
	int		nb;

	nb = get_vertical_danger(map, pos->x, pos->y, 1);
	nb += get_vertical_danger(map, pos->x, pos->y, -1);
	nb += get_horizon_danger(map, pos->x, pos->y, 1);
	nb += get_horizon_danger(map, pos->x, pos->y, -1);
	return (nb);
}


static void	calc_dist(t_map *map, t_coord *poss, t_coord *coord)
{
	int		len;

	len = (ft_power(coord->x - poss->x, 2) +
			ft_power(coord->y - poss->y, 2)) - 
		4 * ft_power(is_free(map, poss), 2) -
		4 * ft_power(is_danger(map, coord), 2) -
		get_point_weight(map, poss->x, poss->y, 0) / 2 -
		get_free_path(map, poss, coord);
	if (map->len == -1 || len < map->len)
	{
		map->x = poss->x;
		map->y = poss->y;
		map->len = len;
	}
}

void		get_best_piece(t_map *map)
{
	t_list	*tmp;
	t_list	*wl;
	t_coord	*poss;
	t_coord	*coord;

	tmp = map->list;
	wl = map->wl;
	while (wl)
	{
		coord = (t_coord*)wl->content;
		while (tmp)
		{
			poss = (t_coord*)tmp->content;
			calc_dist(map, poss, coord);
			tmp = tmp->next;
		}
		wl = wl->next;
	}
}
