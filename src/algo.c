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

int find_way(t_env *e, t_room *current, char *previous, int i)
{
	t_list	*list;
	t_tube	*way;
	t_room	*room;
	char	*next;
	int		min;
	int		last;

	room = current;
	next = NULL;
	list = e->tubes;
	if (room->flag == END)
		return (0);
	if (is_visited(room))
		return (-1);
	room->find = 1;
	min = INT_MAX;
	while (list)
	{
		way = (t_tube*)list->data;
		if (!way->visited)
		{
			next = cmp_tube_room(room->name, way);
			if (next && ft_strcmp(next, previous) && !is_visited(get_room_by_name(e, next)))
			{
				way->visited = 1;
				if ((last = (find_way(e, get_room_by_name(e, next), room->name, i))) < min && last != -1)
					min = 1 + last;
			}
		}
		list = list->next;
	}
	room->find = 0;
	if (min == INT_MAX)
		return (-1);
	else
		return (min);
}

void  set_algo(t_env *e)
{
	int x;

	reset_find_room(e);
	x = find_way(e, get_start_room(e), NULL, 0);
	//printf("x = %d\n", x);
	if (x < 0 || x == INT_MAX)
	{
		ft_putstr_error("Map impossible.\n");
		destroy_all(e);
		exit(1);
	}
	reset_find_room(e);
	reset_visit_tube(e);
}
