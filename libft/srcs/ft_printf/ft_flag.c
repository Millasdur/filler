/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 13:22:27 by hlely             #+#    #+#             */
/*   Updated: 2018/04/26 10:10:51 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			get_flag(char *str, int flags)
{
	int		i;

	i = 0;
	while (str[i] && !is_converter(str[i]))
	{
		flags |= (str[i] == '#') ? HASH : flags;
		flags |= (str[i] == '+') ? PLUS : flags;
		flags |= (str[i] == '-') ? MINUS : flags;
		flags |= (str[i] == ' ') ? SPACE : flags;
		i++;
	}
	return (flags);
}
