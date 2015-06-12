/* ---- HEADER ---- */

#include "lemin.h"

int game_over(t_env *e)
{
	t_list *list;
	t_ant  *temp;
	int 	i;

	i = e->ant_number;
	list = e->ants;
	while (list)
	{
		temp = (t_ant*)list->data;
		if (temp->flag == END)
			i--;
		list = list->next;
	}
	return (i);
}

int can_enter(char *name, t_env *e)
{
	t_room *temp;

	temp = get_room_by_name(e, name);
	if (temp->flag == END)
		return (1);
	else if (temp->full)
		return (0);
	return (1);
}

char *find_way_ant(t_env *e, t_ant *ant)
{
	t_list *list;
	t_tube *way;
	char *next;
	char *next_ret;
	int min;
	int last;

	min = INT_MAX;
	list = e->tubes;
	next = NULL;
	next_ret = NULL;
	while (list && min != 1)
	{
		way = (t_tube*)list->data;
		if (!way->visited)
		{
			next = cmp_tube_room(ant->room->name, way);
			if (next && can_enter(next, e) && ft_strcmp(next, ant->previous))
			{
				if ((last = (find_way(e, get_room_by_name(e, next), ant->room->name, 0))) < min
					&& last > -1)
				{
					way->visited = 1;
					min = 1 + last;
					next_ret = next;
					//printf("Way ant = %d\n", min);
				}
			}			
		}	
		list = list->next;	
	}
	reset_visit_tube(e);
	return (next_ret);
}

t_path	*fill_path(char *name);
{
	t_path	*new;

	if (!new = malloc(sizeof(t_path))))
		return (NULL);
		new->path = ft_strdup(name);
	return (new);
}

int move(t_ant *ant, t_env *e)
{
	char	*new_room;
	t_room	*temp;

 	new_room = NULL;
	if ((new_room = find_way_ant(e, ant)) != NULL)
	{
		ant->path = ft_lst_push(ant->path, fill_path);
		ant->room->full--;
		ant->previous = ant->room->name;
		temp = get_room_by_name(e, new_room);
		ant->room = temp;
		ant->flag = temp->flag;
		temp->full++;
		ft_putchar('L');
		ft_putnbr(ant->id);
		ft_putstr("-");
		ft_putstr(new_room);
		ft_putchar(' ');
		return (1);
	}
	return (0);
}

int game_loop(t_env *e)
{
	t_list *list;
	t_ant 	*temp;
	int i;

	i = 0;
	while(game_over(e))
	{
		list = e->ants;
		while (list)
		{
			temp = (t_ant*)list->data;
			if (temp->flag != END)
				move(temp, e);
			list = list->next;
		}
		i++;
		ft_putchar('\n');
	}
	ft_putstr("TURN = ");
	ft_putnbr(i);
	ft_putchar('\n');
	return (1);
}

