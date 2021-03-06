/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/23 14:10:13 by hlely             #+#    #+#             */
/*   Updated: 2018/04/23 14:12:57 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabdel(char ***tab)
{
	int		i;

	i = 0;
	if (tab && *tab)
	{
		while ((*tab)[i])
		{
			ft_strdel(&((*tab)[i]));
			i++;
		}
		free(*tab);
		*tab = NULL;
	}
}
