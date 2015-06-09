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
	return (0);
}

/* A TESTER */ 

int valid_path(t_env *e, t_room *current, char *previous, int i)
{
	t_list *list;
	t_tube *way;
	
	list = e->tubes;
	current->find++;
	while (list && current->flag != END && i < 10000)
	{
		i++;
		way = (t_tube*)list->data;
		if (!is_visited(get_room_by_name(e, way->out2))
			&& check_way(current, previous, way->out1))
		{
				valid_path(e, get_room_by_name(e, way->out2), current->name, i);
				return (0);
		}
		if (!is_visited(get_room_by_name(e, way->out1))
			&& check_way(current, previous, way->out2))
		{
			 valid_path(e, get_room_by_name(e, way->out1), current->name, i);
			 return (0);
		}
		list = list->next;
	}
	if (current->flag != END)
		return (1);
	return (0);
}

