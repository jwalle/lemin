/* ---- HEADER ------- */

#include "lemin.h"

int	find_way_two(t_tube *way, char *previous, t_env *e, t_room *room)
{
	char	*next;
	int		last;
	int		min;

	min = e->min_two;
	next = NULL;
	if (!way->visited)
	{
		next = cmp_tube_room(room->name, way);
		if (next && ft_strcmp(next, previous)
			&& !is_visited(get_room_by_name(e, next)))
		{
			way->visited = 1;
			if ((last = (find_way(e, get_room_by_name(e, next), room->name)))
				<= min && last != -1)
				min = 1 + last;
		}
	}
	return (min);
}


int find_way(t_env *e, t_room *current, char *previous)
{
	t_list	*list;
	t_tube	*way;
	/*int		min;*/

	list = e->tubes;
	if (current->flag == END)
		return (0);
	if (is_visited(current))
		return (-1);
	current->find = 1;
	e->min_two = INT_MAX;
	while (list)
	{
		way = (t_tube*)list->data;
		e->min_two = find_way_two(way, previous, e, current);
		list = list->next;
	}
	current->find = 0;
	if (e->min_two == INT_MAX)
		return (-1);
	else
		return (e->min_two);
}
