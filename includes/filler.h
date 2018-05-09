/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlely <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/09 13:48:09 by hlely             #+#    #+#             */
/*   Updated: 2018/05/09 16:22:15 by hlely            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct			s_map
{
	int			xmax;
	int			ymax;
	char		c;
	char		**map;

}						t_map;

t_map					init_map(void);
t_map					get_map(t_map map);

#endif
