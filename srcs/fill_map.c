/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:02:26 by hlely             #+#    #+#             */
/*   Updated: 2018/05/18 14:48:26 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	get_tetridim(t_map *map, char *line)
{
	int		i;

	i = 0;
	if (map->tetri)
		free(map->tetri);
	map->tetri = NULL;
	while (line && line[i] && line[i] != ' ')
		i++;
	map->ty = ft_atoi(line + i);
	i++;
	while (line && line[i] && line[i] != ' ')
		i++;
	map->tx = ft_atoi(line + i);
	map->tetri = ft_memalloc(sizeof(char*) * (map->ty + 1));
}

static void	create_shifted(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->ty - map->dy)
	{
		j = 0;
		while (j < map->tx - map->dx)
		{
			map->tetri[i][j] = map->tetri[i + map->dy][j + map->dx];
			j++;
		}
		i++;
	}
	i = 0;
	while (i < map->ty)
	{
		j = (i < map->ty - map->dy) ? map->tx - map->dx : 0;
		while (j < map->tx)
		{
			map->tetri[i][j] = '.';
			j++;
		}
		i++;
	}
}

static void	shift_tetri(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->ty && only_horiz_dot(map, i))
	{
		map->dy++;
		i++;
	}
	i = 0;
	while (i < map->tx && only_vert_dot(map, i))
	{
		map->dx++;
		i++;
	}
	create_shifted(map);
}

void		get_new_val(t_map *map)
{
	int		i;

	i = 0;
	while (i < map->ty && !only_horiz_dot(map, i))
	{
		map->nty++;
		i++;
	}
	i = 0;
	while (i < map->tx && !only_vert_dot(map, i))
	{
		map->ntx++;
		i++;
	}
}

t_map		fill_piece(t_map map)
{
	int		i;
	char	*line;

	i = 0;
	map.dx = 0;
	map.dy = 0;
	get_next_line(STDIN_FILENO, &line);
	get_tetridim(&map, line);
	ft_strdel(&line);
	while (i < map.ty)
	{
		get_next_line(STDIN_FILENO, &line);
		ft_strdel(&(map.tetri[i]));
		map.tetri[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	shift_tetri(&map);
	get_new_val(&map);
	return (map);
}
