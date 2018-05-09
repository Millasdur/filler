/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv31.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 08:54:49 by hlely             #+#    #+#             */
/*   Updated: 2018/05/05 09:05:09 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv31(int c, unsigned char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x1F) | 0xA0;
	res[0] = 0xE0;
	return (3);
}

int		conv32(int c, unsigned char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x3F) | 0x80;
	res[0] = 0xE1;
	return (3);
}

int		conv33(int c, unsigned char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x3F) | 0x80;
	res[0] = ((c >> 12) & 0x1) | 0xE2;
	return (3);
}

int		conv34(int c, unsigned char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x3F) | 0x80;
	res[0] = ((c >> 12) & 0x3) | 0xE4;
	return (3);
}

int		conv35(int c, unsigned char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x3F) | 0x80;
	res[0] = ((c >> 12) & 0x3) & 0xE8;
	return (3);
}
