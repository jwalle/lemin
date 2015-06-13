/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   misc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 16:37:48 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/01 16:38:19 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

int			ft_putstr_error(char *s)
{
	ft_putstr(s);
	exit(0);
	return (0);
}

void reset_find_room(t_env *e)
{
	t_list *list;
	t_room *temp;

	list = e->rooms;
	while (list)
	{
		temp = (t_room*)list->data;
		temp->find = 0;
		list = list->next;
	}
}

void reset_visit_tube(t_env *e)
{
	t_list *list;
	t_tube *temp;

	list = e->tubes;
	while (list)
	{
		temp = (t_tube*)list->data;
		temp->visited = 0;
		list = list->next;
	}
}

void	ft_init(t_env *e)
{
	e->rooms = NULL;
	e->tubes = NULL;
	e->ants = NULL;
	e->start = 0;
	e->end = 0;
	e->ant_number = 0;
}

int is_visited(t_room *next)
{
	if (next->find)
		return (1);
	return (0);
}
