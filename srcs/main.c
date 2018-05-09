/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:43:22 by hlely             #+#    #+#             */
/*   Updated: 2018/05/09 15:34:28 by hlely            ###   ########.fr       */
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
	while (ret)
	{
	}
	return (map);
}

int		main(void)
{
	t_map	map;

	map = init_map();
	map = get_map(map);
	return (0);
}
