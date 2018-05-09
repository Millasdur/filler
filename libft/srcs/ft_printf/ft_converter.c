/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_converter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 12:09:26 by hlely             #+#    #+#             */
/*   Updated: 2018/04/26 09:57:12 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			is_converter(char c)
{
	int		j;

	j = 0;
	while (g_function[j].value)
	{
		if (g_function[j].value == c)
			return (1);
		j++;
	}
	return (0);
}

int			check_attr(char *str, t_opt *opt)
{
	int		i;
	char	*tmp;

	i = 0;
	while (str[i] && !is_converter(str[i]))
		i++;
	tmp = ft_strsub(str, 0, i);
	if ((ft_strchr(tmp, 'l') && ft_strchr(tmp, 'h')) ||
			(ft_strchr(tmp, 'l') && ft_strchr(tmp, 'j')) ||
			(ft_strchr(tmp, 'h') && ft_strchr(tmp, 'j')) ||
			(ft_strchr(tmp, 'h') && ft_strchr(tmp, 'z')) ||
			(ft_strchr(tmp, 'z') && ft_strchr(tmp, 'j')) ||
			(ft_strchr(tmp, 'l') && ft_strchr(tmp, 'z')))
	{
		opt->modif = J_MODE;
		ft_strdel(&tmp);
		return (1);
	}
	ft_strdel(&tmp);
	return (0);
}

char		*convert(va_list *arg, char c, char *flags, t_opt *opt)
{
	int		j;
	int		len;

	j = 0;
	len = 0;
	opt->charac = c;
	while (g_function[j].value)
	{
		if (g_function[j].value == c)
		{
			get_attr(arg, flags, opt);
			return (g_function[j].f(arg, opt));
		}
		j++;
	}
	get_attr(arg, flags, opt);
	return (ft_else(arg, opt));
}
