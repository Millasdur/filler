/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 21:47:24 by hlely             #+#    #+#             */
/*   Updated: 2018/05/13 12:50:17 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		show_all_possibilities(t_list *list)
{
	t_list		*tmp;

	tmp = list;
	while (tmp)
	{
		ft_dprintf(2, "POSABLE IN [%d %d]\n",
				((t_coord*)tmp->content)->x, ((t_coord*)tmp->content)->y);
		tmp = tmp->next;
	}
}

void		delete_possibilities(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = *list;
		*list = (*list)->next;
		free(tmp->content);
		free(tmp);
	}
	*list = NULL;
}

int			can_put(t_map *map, char **tetri, int y, int x)
{
	int		i;
	int		j;
	int		nb;

	i = 0;
	nb = 0;
	while (i < map->ty)
	{
		j = 0;
		while (j < map->tx)
		{
			if (tetri[i][j] == '*')
			{
				if (map->map[y + i][x + j] != '.' &&
						map->map[y + i][x + j] != map->c)
					return (0);
				if (map->map[y + i][x + j] != '.' &&
						map->map[y + i][x + j] == map->c)
					nb++;
			}
			j++;
		}
		i++;
	}
	return (nb == 1 ? 1 : 0);
}

int			get_posable_list(t_map *map, char **tetri)
{
	int			i;
	int			j;
	int			nb;
	t_coord		point;

	i = 0;
	nb  = 0;
	/* ft_dprintf(2, "ymax[%d] ty[%d]\n", map->ymax, map->ty); */
	while (i < map->ymax - map->ty + 1)
	{
		j = 0;
		while (j < map->xmax - map->tx + 1)
		{
			if (can_put(map, tetri, i, j))
			{
				point.x = i;
				point.y = j;
				ft_lstaddlast(&map->list, ft_lstnew(&point, sizeof(t_coord)));
				nb++;
			}
			j++;
		}
		i++;
	}
	return (nb);
}

int			put_piece(t_map *map)
{
	int		nb;

	nb = get_posable_list(map, map->tetri);
	/* ft_dprintf(2, "nb poss [%d]\n", nb); */
	if (nb == 0)
		return (0);
	/* show_all_possibilities(map->list); */
	/* ft_dprintf(2, "let's put : "); */
	/* ft_dprintf(2, "[%d %d]\n", */
	/* 		((t_coord*)map->list->content)->x, ((t_coord*)map->list->content)->y); */
	get_best_move(map);
	ft_printf("%d %d\n", map->x, map->y);
	/* ft_printf("%d %d\n", */
	/* 		((t_coord*)map->list->content)->x, ((t_coord*)map->list->content)->y); */
	/* ft_dprintf(2, "let's del the solutions\n"); */
	delete_possibilities(&map->list);
	delete_weight_map(map);
	/* ft_dprintf(2, "Deleted solutions\n"); */
	return (1);
}
