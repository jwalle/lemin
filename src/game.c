/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/13 16:39:59 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/13 16:40:02 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int game_over(t_env *e)
{
	t_list	*list;
	t_ant	*temp;
	int		i;

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

	temp = get_room_by_name(e, name);
	if (temp->flag == END)
		return (1);
	else if (temp->full)
		return (0);
	else if (!check_path(ant, name))
		return (0);
	return (1);
}

int move(t_ant *ant, t_env *e, int n)
{
	char	*new_room;
	t_room	*temp;
	t_list	*list;

	new_room = NULL;
	if ((new_room = find_way_ant(e, ant)) != NULL)
	{
		list = ant->path;
		ant->path = ft_lst_push(list, fill_path(ant->room->name));
		ant->room->full--;
		ant->previous = ant->room->name;
		temp = get_room_by_name(e, new_room);
		ant->room = temp;
		ant->flag = temp->flag;
		temp->full++;
		if (n)
			ft_putchar(' ');
		ft_putchar('L');
		ft_putnbr(ant->id);
		ft_putstr("-");
		ft_putstr(new_room);
		free(new_room);
		return (1);
	}
	return (0);
}

int	game_loop(t_env *e)
{
	t_list	*list;
	t_ant	*temp;
	int		n;

	while (game_over(e))
	{
		list = e->ants;
		n = 0;
		while (list)
		{
			temp = (t_ant*)list->data;
			if (temp->flag != END)
				n += move(temp, e, n);
			list = list->next;
		}
		ft_putchar('\n');
		if (n == 0)
			ft_putstr_error("Map error, no more move.\n");
	}
	return (1);
}
