/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 14:43:58 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/01 16:39:10 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
#define LEMIN_H

#include "../libft/libft.h"
#include <stdlib.h>

typedef struct	s_env
{
				int i;
				int start;
				int end;
}				t_env;

int		get_next_line(int fd, char **line);
int		ft_putstr_error(char *s);
int		parse(t_env *e, char *line, int ret);

#endif
