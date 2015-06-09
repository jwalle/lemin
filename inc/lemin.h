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
#include <stdio.h> /* PRINTF */

# define START 1
# define END 3
# define NORMAL 2
# define EVENODD(a) ((a) % 2 == 0 ? 1 : 0)

typedef struct		s_room
{
	int				flag;
	char			*name;
	int				x;
	int				y;
	int 			full;
	int 			find;
}					t_room;

typedef struct		s_tube
{
	char			*out1;
	char			*out2;
}					t_tube;

typedef struct      s_ant
{
	int 			id;
	int 			as_moved;
	int 			flag;
	t_room 			*room;
	char 			*previous;
} 					t_ant;

typedef struct		s_env
{
	int				ant_number;
	int				i;
	int 			start;
	int				end;
	t_list			*rooms;
	t_list			*tubes;
	t_list 			*ants;
}					t_env;

int 	game_loop(t_env *e);
int		get_next_line(int fd, char **line);
int		ft_putstr_error(char *s);
int		parse(t_env *e, char *line, int ret);
int		is_room(char *line);
int		is_tube(char *line);
t_room	*stock_room(char *line, t_env *e, int flag);
t_tube	*stock_tube(char *line);
void 	set_algo(t_env *e);
void 	find_way(t_env *e, t_room *current, char *previous, int i);
t_room  *get_room_by_name(t_env *e, char *name);
t_room  *get_start_room(t_env *e);
int 	init_ants(t_env *e);
int 	valid_path(t_env *e, t_room *current, char *previous, int i);
int     check_way(t_room *current, char *previous, char *out);
int 	is_visited(t_room *next);
void 	reset_find_room(t_env *e);

#endif
