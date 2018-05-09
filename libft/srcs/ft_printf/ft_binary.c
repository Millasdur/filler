/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 09:30:14 by hlely             #+#    #+#             */
/*   Updated: 2018/04/26 09:35:05 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_binary(va_list *arg, t_opt *opt)
{
	uintmax_t	nb;
	char		*res;

	nb = get_unumber(arg, *opt);
	opt->flags ^= (nb == 0) ? (opt->flags & HASH) : 0;
	res = ft_uitoa_base(nb, 2);
	if (ft_strequ(res, "0") && opt->preci == 0)
	{
		ft_strdel(&res);
		res = ft_strdup("");
	}
	ft_lowercase(&res);
	res = handle_number_flag(res, opt, HEX);
	opt->len2 = ft_strlen(res);
	opt->len += ft_strlen(res);
	return (res);
}
