/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wchar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 11:10:06 by hlely             #+#    #+#             */
/*   Updated: 2018/05/05 11:20:35 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_w1(int c, unsigned char res[])
{
	res[0] = c;
	return (1);
}

int		ft_w2(int c, unsigned char res[])
{
	res[1] = (c & 0x3F) | (0x80);
	res[0] = ((c >> 6) & 0x1F) | 0xC0;
	return (2);
}

int		ft_w3(wchar_t c, unsigned char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x3F) | (0x80);
	res[0] = (c >> 12) | (0xE0);
	return (3);
}

int		ft_w4(int c, unsigned char res[])
{
	if (c >= 0x10000 && c <= 0x1FFFF)
		return (conv41(c, res));
	if (c >= 0x20000 && c <= 0x3FFFF)
		return (conv42(c, res));
	if (c >= 0x40000 && c <= 0x7FFFF)
		return (conv43(c, res));
	if (c >= 0x80000 && c <= 0xFFFFF)
		return (conv44(c, res));
	if (c >= 0x100000 && c <= 0x10FFFF)
		return (conv45(c, res));
	return (-1);
}

int		ft_getwint(unsigned int c, unsigned char res[])
{
	if ((c >= 0xD800 && c <= 0xDFFF) || (c > 0xD7FF && c < 0xE000) ||
			c == 0xbffe || c == 256)
		return (-1);
	if (c <= 127)
		return (ft_w1(c, res));
	else if (c >= 0x80 && c <= 0x7FF)
		return (ft_w2(c, res));
	else if (c >= 0x800 && c <= 0xFFFF)
		return (ft_w3(c, res));
	else if (c >= 0x10000 && c <= 0x10FFFF)
		return (ft_w4(c, res));
	return (-1);
}
