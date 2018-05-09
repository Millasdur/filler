/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 08:55:19 by hlely             #+#    #+#             */
/*   Updated: 2018/05/05 09:07:13 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				conv41(int c, unsigned char res[])
{
	res[3] = (c & 0x3F) | (0x80);
	res[2] = ((c >> 6) & 0x3F) | 0x80;
	res[1] = ((c >> 12) & 0xF) | 0x90;
	res[0] = 0xF0;
	return (4);
}

int				conv42(int c, unsigned char res[])
{
	res[3] = (c & 0x3F) | (0x80);
	res[2] = ((c >> 6) & 0x3F) | 0x80;
	res[1] = ((c >> 12) & 0x1F) | 0xA0;
	res[0] = 0xF0;
	return (4);
}

int				conv43(int c, unsigned char res[])
{
	res[3] = (c & 0x3F) | (0x80);
	res[2] = ((c >> 6) & 0x3F) | 0x80;
	res[1] = ((c >> 12) & 0x3F) | 0x80;
	res[0] = 0xF1;
	return (4);
}

int				conv44(int c, unsigned char res[])
{
	res[3] = (c & 0x3F) | (0x80);
	res[2] = ((c >> 6) & 0x3F) | 0x80;
	res[1] = ((c >> 12) & 0x3F) | 0x80;
	res[0] = ((c >> 18) & 0x1) | 0xF2;
	return (4);
}

int				conv45(int c, unsigned char res[])
{
	res[3] = (c & 0x3F) | (0x80);
	res[2] = ((c >> 6) & 0x3F) | 0x80;
	res[1] = ((c >> 12) & 0xF) | 0x80;
	res[0] = 0xF4;
	return (4);
}
