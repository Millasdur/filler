/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 16:02:26 by hlely             #+#    #+#             */
/*   Updated: 2018/05/09 16:21:51 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_tetri	parse_tetri(void)
{
	int		i;
	char	*line;
	t_tetri	tetri;

	i = 0;
	get_next_line(STDIN_FILENO, &line);
	tetri.ymax = ft_atoi(line + 6);
	tetri.xmax = ft_atoi(line + 8);
	tetri.shape = ft_memalloc(sizeof(char*) * (tetri.ymax + 1));
	ft_strdel(&line);
ft_printf("tetri:\n");
	while (i < tetri.ymax)
	{
		get_next_line(STDIN_FILENO, &line);
ft_printf("%s\n", line);
		tetri.shape[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	return (tetri);
}

t_map	putpart(t_map map)
{
	return (map);
}
