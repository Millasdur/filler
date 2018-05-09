/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_attr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 15:06:21 by hlely             #+#    #+#             */
/*   Updated: 2018/04/26 10:10:59 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	get_preci(va_list *arg, char *str)
{
	int		i;
	int		preci;

	i = 0;
	preci = -1;
	while (str[i] && !is_converter(str[i]))
	{
		if (str[i] == '.')
		{
			i++;
			if (str[i] == '*')
			{
				preci = va_arg(*arg, int);
				preci = (preci < 0) ? -1 : preci;
			}
			else
				preci = ft_atoi(str + i);
			while (str[i] && str[i + 1] &&
					!is_converter(str[i + 1]) && ft_isdigit(str[i]))
				i++;
		}
		i++;
	}
	return (preci);
}

static int	get_width(va_list *arg, char *str, t_opt *opt)
{
	int		i;
	int		width;

	i = 0;
	width = 0;
	while (str[i] && !is_converter(str[i]) && str[i] != '.')
	{
		if (str[i] == '*')
		{
			width = va_arg(*arg, int);
			opt->flags |= (width < 0) ? MINUS : opt->flags;
			width = ft_abs(width);
			i++;
		}
		else if (ft_isdigit(str[i]) || str[i] == '0')
		{
			width = ft_atoi(str + i);
			while (str[i] && !is_converter(str[i]) && ft_isdigit(str[i]))
				i++;
		}
		else
			i++;
	}
	return (width);
}

static int	get_zero(char *str)
{
	int		i;
	int		zero;

	i = 0;
	zero = 0;
	while (str[i] && !is_converter(str[i]) && str[i] != '.'
			&& !ft_isdigit(str[i]))
		i++;
	if (str[i] && str[i] == '0')
		zero = 1;
	return (zero);
}

static int	get_modif(char *str)
{
	int		i;
	int		modif;

	i = 0;
	modif = 0;
	while (str[i] && !is_converter(str[i]))
	{
		if (ft_strchr("lhjz", str[i]))
		{
			if (str[i] == 'l' && str[i + 1] && str[i + 1] == 'l')
				modif = LL_MODE;
			else if (str[i] == 'l' && str[i + 1] && str[i + 1] != 'l')
				modif = L_MODE;
			else if (str[i] == 'h' && str[i + 1] && str[i + 1] == 'h')
				modif = HH_MODE;
			else if (str[i] == 'h' && str[i + 1] && str[i + 1] != 'h')
				modif = H_MODE;
			else if (str[i] == 'j')
				modif = J_MODE;
			else if (str[i] == 'z')
				modif = Z_MODE;
		}
		i += (modif == HH_MODE || modif == LL_MODE) ? 2 : 1;
	}
	return (modif);
}

void		get_attr(va_list *arg, char *str, t_opt *opt)
{
	opt->flags = 0;
	opt->width = get_width(arg, str, opt);
	opt->preci = get_preci(arg, str);
	opt->zero = get_zero(str);
	opt->flags = get_flag(str, opt->flags);
	if (!check_attr(str, opt))
		opt->modif = get_modif(str);
}
