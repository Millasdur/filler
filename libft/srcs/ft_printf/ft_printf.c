/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 09:55:29 by hlely             #+#    #+#             */
/*   Updated: 2018/05/05 09:20:58 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_function	g_function[] =
{
	{'s', &ft_string},
	{'S', &ft_bigstring},
	{'p', &ft_pointer},
	{'c', &ft_char},
	{'C', &ft_wchar},
	{'d', &ft_int},
	{'D', &ft_maxiint},
	{'i', &ft_int},
	{'o', &ft_octal},
	{'O', &ft_maxioctal},
	{'x', &ft_minihexa},
	{'X', &ft_maxihexa},
	{'u', &ft_uint},
	{'U', &ft_umaxiint},
	{'%', &ft_percent},
	{'b', &ft_binary},
	{0, NULL}
};

int				is_attr(char c)
{
	char	*tmp;

	tmp = "0123456789.-+* #lhjz";
	if (ft_strchr(tmp, c) != NULL)
		return (1);
	return (0);
}

static t_opt	setup_struct(void)
{
	t_opt	opt;

	opt.i = 0;
	opt.len = 0;
	opt.len2 = 0;
	opt.len_tmp = 0;
	opt.positive = 1;
	return (opt);
}

char			*prepare_convertion(va_list *arg,
		char **str, t_opt *opt, char *res)
{
	int		j;
	char	*tmp;
	char	*tmp2;

	tmp = ft_strsub(*str, 0, opt->i);
	opt->len_tmp = opt->len;
	opt->len += opt->i;
	*str += opt->i + 1;
	opt->i = 0;
	j = opt->i;
	while ((*str)[opt->i] && is_attr((*str)[opt->i]))
		(opt->i)++;
	tmp2 = convert(arg, (*str)[opt->i], *str + j, opt);
	if (tmp2 == NULL)
	{
		ft_putnstr(res, opt->len);
		ft_strdel(&res);
		return (NULL);
	}
	res = ft_strnjoinddel(res, tmp, opt->len_tmp, ft_strlen(tmp));
	res = ft_strnjoinddel(res, tmp2, opt->len - opt->len2, opt->len2);
	*str += opt->i;
	(*str)[0] ? (*str)++ : 0;
	opt->i = 0;
	return (res);
}

int				ft_printf(char *str, ...)
{
	char	*res;
	va_list	arg;
	t_opt	opt;

	opt = setup_struct();
	va_start(arg, str);
	res = ft_strdup("");
	while (str && str[(opt.i)])
	{
		if (str[opt.i] == '%')
			res = prepare_convertion(&arg, &str, &opt, res);
		else
			(opt.i)++;
		if (res == NULL)
			return (-1);
	}
	va_end(arg);
	res = ft_strnjoindel(res, str, opt.len, ft_strlen(str));
	opt.len += ft_strlen(str);
	ft_putnstr(res, opt.len);
	ft_strdel(&res);
	return (opt.len);
}

int				ft_printf_fd(int fd, char *str, ...)
{
	char	*res;
	va_list	arg;
	t_opt	opt;

	opt = setup_struct();
	va_start(arg, str);
	res = ft_strdup("");
	while (str[opt.i])
	{
		if (str[opt.i] == '%')
			res = prepare_convertion(&arg, &str, &opt, res);
		else
			(opt.i)++;
	}
	va_end(arg);
	res = ft_strnjoindel(res, str, opt.len, ft_strlen(str));
	opt.len += ft_strlen(str);
	write(fd, res, opt.len);
	ft_strdel(&res);
	return (opt.len);
}
