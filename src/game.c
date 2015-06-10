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

	list = e->tubes;
	while (list)
	{
		way = (t_tube*)list->data;
		if (!ft_strcmp(ant->room->name, way->out1)
			&& ft_strcmp(ant->previous, way->out1)
			&& ft_strcmp(ant->previous, way->out2)
			&& can_enter(way->out2, e)
			&& ant->flag != END
			&& !valid_path(e, get_room_by_name(e, way->out1), ant->previous, 0))
			return (way->out2);
		if (!ft_strcmp(ant->room->name, way->out2)
			&& ft_strcmp(ant->previous, way->out2)
			&& ft_strcmp(ant->previous, way->out1)
			&& can_enter(way->out1, e)
			&& ant->flag != END
			&& !valid_path(e, get_room_by_name(e, way->out2), ant->previous, 0))
			return (way->out1);
		list = list->next;
	}
	return (NULL);
}


int move(t_ant *ant, t_env *e)
{
	char *new_room;
	t_room *temp;

	if ((new_room = find_way_ant(e, ant)) != NULL)
	{
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
			move(temp, e);
			list = list->next;
		}
		i++;
		ft_putchar('\n');
		/* re_init_turn(e);*/
	}
	ft_putstr("TURN = ");
	ft_putnbr(i);
	ft_putchar('\n');
	return (1);
}

