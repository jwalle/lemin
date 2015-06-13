/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 16:40:19 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/13 16:40:22 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*cmp_tube_room(char *room, t_tube *way)
{
	if (!ft_strcmp(room, way->out1))
		return (way->out2);
	else if (!ft_strcmp(room, way->out2))
		return (way->out1);
	return (NULL);
}

void	set_algo(t_env *e)
{
	int x;

	reset_find_room(e);
	x = find_way(e, get_start_room(e), NULL);
	if (x < 0 || x == INT_MAX)
	{
		ft_putstr_error("Map impossible.\n");
		destroy_all(e);
		exit(1);
	}
	reset_find_room(e);
	reset_visit_tube(e);
}

t_room	*get_start_room(t_env *e)
{
	t_list	*list;
	t_room	*current;

	list = e->rooms;
	while (list)
	{
		current = (t_room*)list->data;
		if (current->flag == START)
			break ;
		list = list->next;
	}
	return (current);
}

t_room	*get_room_by_name(t_env *e, char *name)
{
	t_list	*list;
	t_room	*current;

	list = e->rooms;
	while (list)
	{
		current = (t_room*)list->data;
		if (!ft_strcmp(name, current->name))
			break ;
		list = list->next;
	}
	return (current);
}

int		check_way(t_room *current, char *previous, char *out)
{
	if (!ft_strcmp(current->name, out)
		&& ft_strcmp(previous, out)
		&& current->flag != END)
		return (1);
	return (0);
}
