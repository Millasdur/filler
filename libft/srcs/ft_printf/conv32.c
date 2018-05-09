/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv32.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/05 08:50:19 by hlely             #+#    #+#             */
/*   Updated: 2018/05/05 09:05:34 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		conv36(int c, unsigned char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x3F) | 0x80;
	res[0] = 0xEC;
	return (3);
}

int		conv37(int c, unsigned char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x1F) | 0x9F;
	res[0] = 0xED;
	return (3);
}

int		conv38(int c, unsigned char res[])
{
	res[2] = (c & 0x3F) | (0x80);
	res[1] = ((c >> 6) & 0x3F) | 0x80;
	res[0] = ((c >> 12) & 0x1) | 0xEE;
	return (3);
}
