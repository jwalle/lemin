/* ---- HEADER ------- */

#include "lemin.h"

t_room *get_start_room(t_env *e)
{
	t_list *list;
	t_room *current;
	
	list = e->rooms;
	while (list)
	{
		current = (t_room*)list->data;
		if (current->flag == START)
			break;
		list = list->next;
	}
	return (current);
}

t_room *get_room_by_name(t_env *e, char *name)
{
	t_list *list;
	t_room *current;
	
	list = e->rooms;
	while (list)
	{
		current = (t_room*)list->data;
		if (!ft_strcmp(name, current->name))
			break;
		list = list->next;
	}
	return (current);
}

int is_visited(t_room *next)
{
	if (next->find)
		return (1);
	return (0);
}

int check_way(t_room *current, char *previous, char *out)
{
	if (!ft_strcmp(current->name, out)
		&& ft_strcmp(previous, out)
		&& current->flag != END)
		return (1);
	return (0);
}

void find_way(t_env *e, t_room *current, char *previous, int i)
{
	t_list *list;
	t_tube *way;
	
	list = e->tubes;
	current->find++;
	while (list && current->flag != END && i < 1000000)
	{
		i++;
		way = (t_tube*)list->data;
		if (!is_visited(get_room_by_name(e, way->out2))
			&& check_way(current, previous, way->out1))
		{
				find_way(e, get_room_by_name(e, way->out2), current->name, i);
				return ;
		}
		if (!is_visited(get_room_by_name(e, way->out1))
			&& check_way(current, previous, way->out2))
		{
			 find_way(e, get_room_by_name(e, way->out1), current->name, i);
			 return ;
		}
		list = list->next;
	}
	if (current->flag != END)
	{
		ft_putstr_error("Map impossible.\n");
		destroy_all(e);
		exit(1);
	}
}

void  set_algo(t_env *e)
{
	find_way(e, get_start_room(e), NULL, 0);
	reset_find_room(e);
}
