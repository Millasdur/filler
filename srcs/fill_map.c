/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:02:26 by hlely             #+#    #+#             */
/*   Updated: 2018/05/15 17:44:33 by hlely            ###   ########.fr       */
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

t_map		fill_piece(t_map map)
{
	int		i;
	char	*line;

	i = 0;
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
	return (map);
}
