/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 14:43:58 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/01 20:12:15 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
#define LEMIN_H

#include "../libft/libft.h"
#include <stdlib.h>
#include <stdio.h> // PRINTF

typedef struct		s_room
{
	int				end;
	int				start;
	int				number;
	int				x;
	int				y;
	struct s_room	*next;
}					t_room;

typedef struct		s_tube
{
	int				out1;
	int				out2;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_env
{
	int				ant;
	int				i;
	int 			start;
	int				end;
	t_room			*room;
	t_tube			*tube;
}					t_env;

int		get_next_line(int fd, char **line);
int		ft_putstr_error(char *s);
int		parse(t_env *e, char *line, int ret);
int		is_room(char *line);
int		is_tube(char *line);
int		stock_room(char *line, t_env *e);
int		stock_tube(char *line, t_env *e);

#endif
