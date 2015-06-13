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

void print_path(t_ant *ant)
{
	t_list	*list;
	t_path	*path;

	list = ant->path;
	printf("%d -->", ant->id);
	while (list)
	{
		path = (t_path*)list->data;
		printf("%s->", path->name);
		list = list->next;
	}
	printf("\n");
}

int check_path(t_ant *ant, char *next)
{
	t_list	*list;
	t_path	*path;

	list = ant->path;

	while (list)
	{
		path = (t_path*)list->data;
		if (!ft_strcmp(next, path->name))
			return (0);
		list = list->next;
	}
	return (1);
}

int can_enter(char *name, t_env *e, t_ant *ant)
{
	t_room *temp;

	/*(void)ant;*/
	temp = get_room_by_name(e, name);
	if (temp->flag == END)
		return (1);
	else if (temp->full)
		return (0);
	else if (!check_path(ant, name))
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
	while (list)
	{
		way = (t_tube*)list->data;
		if (!way->visited)
		{
			next = cmp_tube_room(ant->room->name, way);
			if (next && can_enter(next, e, ant) && ft_strcmp(next, ant->previous))
			{
				if ((last = (find_way(e, get_room_by_name(e, next), ant->room->name, 0))) < min
					&& last > -1)
				{
					way->visited = 1;
					min = 1 + last;
					next_ret = next;
				}
			}			
		}
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

int move(t_ant *ant, t_env *e)
{
	char	*new_room;
	t_room	*temp;

 	new_room = NULL;
	if ((new_room = find_way_ant(e, ant)) != NULL)
	{
		ant->path = ft_lst_push(ant->path, fill_path(ant->room->name));
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
			/*print_path(temp);*/
			/*printf("%d -> %s\n", temp->id, temp->room->name);*/
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

