/* ---- HEADER ---- */

#include "lemin.h"

int 	search(t_room *next, t_env *e, char *previous)
{
	t_list	*list;
	t_tube	*way;
	
	list = e->tubes;
	(void)previous;
	if (next->flag == END)
		return (0);
	while (list && next->flag != END)
	{
		way = (t_tube*)list->data;
		if (next->find)
			return (-1);
		next->find++;
		if (!is_visited(get_room_by_name(e, way->out2)) && check_way(next, previous, way->out1))
		{
			return (search(get_room_by_name(e, way->out2), e, next->name) + 1);
		}
		if (!is_visited(get_room_by_name(e, way->out1)) && check_way(next, previous, way->out2))
		{
			 return (search(get_room_by_name(e, way->out1), e, next->name) + 1);
		}
		list = list->next;
		next->find = 0;
	}
	return (INT_MAX);
}

char	*cmp_tube_room(char	*room, t_tube *way)
{
	if (!ft_strcmp(room, way->out1))
		return (way->out2);
	else if (!ft_strcmp(room, way->out2))
		return (way->out1);
	return (NULL);
}


t_room	*find_next(t_room *current, t_env *e)
{
	t_list	*list_tubes;
	t_room	*next_ret;
	t_tube	*way;
	char	*next;
	int		path_size;
	int		size;

	size = 0;
	next_ret = NULL;
	path_size = INT_MAX;
	list_tubes = e->tubes;
	reset_find_room(e);
	while (list_tubes)
	{
		way = (t_tube *)list_tubes->data;
		if ((next = cmp_tube_room(current->name, way)))
		{

			size = search(get_room_by_name(e, next), e, current->name);
			if (size < path_size && size != -1)
			{
				path_size = size + 1;
				next_ret = get_room_by_name(e, next);
			}
		}
		list_tubes = list_tubes->next;
	}
	reset_find_room(e);
	return (next_ret);
}
