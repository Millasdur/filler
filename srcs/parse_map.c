/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 15:52:30 by hlely             #+#    #+#             */
/*   Updated: 2018/05/09 16:32:33 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	init_map(void)
{
	t_map	map;

	map.xmax = -1;
	map.ymax = -1;
	map.map = NULL;
	map.c = 0;
	return (map);
}

t_map	getdim(t_map map, char *line)
{
	int		i;

	i = 0;
	while (line[i] && !ft_isdigit(line[i]))
		i++;
	map.ymax = ft_atoi(line + i);
	while (line[i] && ft_isdigit(line[i]))
		i++;
	map.xmax = ft_atoi(line + i);
	return (map);
}

t_map	fill_map(t_map map)
{
	int		i;
	char	*line;

	i = 0;
	map.map = (char**)ft_memalloc(sizeof(char*) * (map.ymax + 1));
	while (get_next_line(STDIN_FILENO, &line))
	{
		if (!ft_isdigit(*line))
			break ;
		map.map[i] = ft_strdup(line + 4);
		ft_strdel(&line);
		i++;
	}
	return (map);
}

t_map	get_map(t_map map)
{
	int		ret;
	char	*line;

	ret = get_next_line(STDIN_FILENO, &line);
	if (ret && *line == '$')
	{
		map.c = (*(line + 10) == '1') ? 'o' : 'x';
		return (map);
	}
	if (map.xmax == -1)
		map = getdim(map, line);
	ft_strdel(&line);
	get_next_line(STDIN_FILENO, &line);
	ft_strdel(&line);
	map = fill_map(map);
	return (map);
}
