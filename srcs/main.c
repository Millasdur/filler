/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:43:22 by hlely             #+#    #+#             */
/*   Updated: 2018/05/09 16:27:35 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	show_map(t_map map)
{
	int		i;
	int		j;

	j = 0;
	ft_printf("xmax :[%d]\nymax :[%d]\n", map.xmax, map.ymax);
	while (j < map.ymax)
	{
		i = 0;
		ft_printf("%s\n", map.map[j]);
		j++;
	}
}

int		main(void)
{
	int		i;
	t_map	map;

	i = 0;
	map = init_map();
	map = get_map(map);
	show_map(map);
	while (i < map.ymax)
	{
		ft_strdel(&map.map[i]);
		i++;
	}
	free(map.map);
	return (0);
}
