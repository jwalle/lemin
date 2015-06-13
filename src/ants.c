/* ---- HEADER ----- */

#include "lemin.h"

t_ant 	*stock_ant(t_env *e, int id)
{
	t_ant *new;

	if (!(new = malloc(sizeof(t_ant))))
		return (NULL);
	new->path = NULL;
	new->id = id;
	new->room = get_start_room(e);
	new->previous = NULL;
	new->flag = START;
	return (new);
}

int		init_ants(t_env *e)
{
	int i;
	t_room *temp;

	i = 1;
	while (i <= e->ant_number)
	{
		e->ants = ft_lst_push(e->ants, stock_ant(e, i));
		i++;
	}
	temp = get_start_room(e);
	temp->full = e->ant_number + 1;
	return (1);
}

char	*find_way_ant_two(t_tube *way, t_ant *ant, char *next_ret, t_env *e)
{
	char	*next;
	int		last;

	next = NULL;
	if (!way->visited)
	{
		next = cmp_tube_room(ant->room->name, way);
		if (next && can_enter(next, e, ant)
			&& ft_strcmp(next, ant->previous))
		{
			if ((last = (find_way(e, get_room_by_name(e, next), ant->room->name)))
				< e->min && last > -1)
			{
				way->visited = 1;
				e->min = 1 + last;
				next_ret = next;
			}
		}	
	}
	return (next_ret);
}

char *find_way_ant(t_env *e, t_ant *ant)
{
	t_list	*list;
	t_tube	*way;
	char	*next_ret;


	e->min = INT_MAX;
	list = e->tubes;
	next_ret = NULL;
	while (list)
	{
		way = (t_tube*)list->data;
		next_ret = find_way_ant_two(way, ant, next_ret, e);
		reset_visit_tube(e);
		list = list->next;	
	}
	return (next_ret);
}

t_path	*fill_path(char *name)
{
	t_path	*new;

	if (!(new = malloc(sizeof(t_path))))
		return (NULL);
		new->name = ft_strdup(name);
	return (new);
}