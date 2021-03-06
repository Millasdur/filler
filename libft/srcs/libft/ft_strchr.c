/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:29:32 by hlely             #+#    #+#             */
/*   Updated: 2018/05/11 19:00:14 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return ((char*)&(str[i]));
		i++;
	}
	if (str[i] == '\0' && c == '\0')
		return ((char*)&(str[i]));
	return (0);
}
