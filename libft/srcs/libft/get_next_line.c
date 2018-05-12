/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/11 13:41:08 by hlely             #+#    #+#             */
/*   Updated: 2018/05/12 23:31:05 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*getfd(int fd, t_list **list)
{
	t_list		*tmp;
	t_list		*new;
	t_gnl		gnl;

	tmp = *list;
	while (tmp)
	{
		if (((t_gnl*)(tmp->content))->fd == fd)
			return (((t_gnl*)tmp->content)->buf);
		tmp = tmp->next;
	}
	gnl.fd = fd;
	ft_bzero(gnl.buf, BUFF_SIZE + 1);
	new = ft_lstnew(&gnl, sizeof(gnl));
	ft_lstadd(list, new);
	return (((t_gnl*)new->content)->buf);
}

static int		fill_line(char *buf, char **line)
{
	int		i;
	char	tmp[BUFF_SIZE + 1];

	i = ft_indexof(buf, '\n');
	if (i != -1)
		*line = ft_strsub(buf, 0, i);
	else
	{
		*line = ft_strdup(buf);
		ft_bzero(buf, BUFF_SIZE + 1);
		return (0);
	}
	ft_bzero(tmp, BUFF_SIZE + 1);
	ft_strcpy(tmp, buf + i + 1);
	ft_bzero(buf, BUFF_SIZE + 1);
	ft_strcpy(buf, tmp);
	return (1);
}

static int		read_n_fill_line(int i, char *buf, char *tmp)
{
	if (ft_strchr(buf, '\n'))
	{
		tmp = ft_strdup(buf + i + 1);
		ft_bzero(buf, BUFF_SIZE + 1);
		ft_strcpy(buf, tmp);
		ft_strdel(&tmp);
		return (1);
	}
	ft_bzero(buf, BUFF_SIZE + 1);
	return (0);
}

static int		read_n_fill(int fd, char *buf, char **line)
{
	int		i;
	int		ret;
	char	*tmp;

	ft_bzero(buf, BUFF_SIZE + 1);
	ret = read(fd, buf, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	if (ret == 0 && !*line)
		return (2);
	else if (ret == 0 && *line)
		return (1);
	i = ft_strchr(buf, '\n') ? ft_indexof(buf, '\n') : ret;
	tmp = ft_strsub(buf, 0, i);
	*line = ft_strjoinddel(*line, tmp);
	return (read_n_fill_line(i, buf, tmp));
}

int				get_next_line(int fd, char **line)
{
	int				ret;
	char			*buf;
	static t_list	*list = NULL;

	if (fd < 0 || BUFF_SIZE <= 0 || !line)
		return (-1);
	buf = getfd(fd, &list);
	*line = NULL;
	if (ft_strchr(buf, '\n'))
		return (fill_line(buf, line));
	else if (*buf)
		fill_line(buf, line);
	while ((ret = read_n_fill(fd, buf, line)) == 0)
	{
	}
	if (ret == 1)
		return (1);
	if (ret == 2)
		return (0);
	if (ret == -1)
		return (-1);
	return (0);
}
