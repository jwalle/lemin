/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 14:41:15 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/01 20:12:53 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_init(t_env *e)
{
	e->rooms = NULL;
	e->tubes = NULL;
	e->ants = NULL;
	e->start = 0;
	e->end = 0;
	e->ant_number = 0;
}

int 	get_ant_number(t_env *e)
{
	int ret;
	char *line;

	while ((ret = (get_next_line(0, &line)) > 0))
	{
		if (line[0] != '#' && line[1] != '#')
		{
			while (ret)
			{
				if (!ft_isdigit(line[--ret]))
					return (0);
			}
			e->ant_number = ft_atoi(line);
			return (1);
		}
	}
	return (0);
}

int		get_map(t_env *e)
{
	char	*tmp;
	int		ret;

	if (!get_ant_number(e))
		return (0);
	while ((ret = (get_next_line(0, &tmp)) > 0))
	{
		parse(e, tmp, ret);
		free(tmp);
	}
	if (!ret)
		return (1);
	return (0);
}

void print_room_name(char *name, int x, int y, int flag)
{
	if (flag == START)
		ft_putstr("##start\n");
	if (flag == END)
		ft_putstr("##end\n");
	ft_putstr(name);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar(' ');
	ft_putnbr(y);
	ft_putchar('\n');
}

void print_stuff(t_env *e)
{
	t_list 	*list;
	t_room  *temp;
	t_tube  *tump;

	list = e->rooms;
	ft_putnbr(e->ant_number);
	ft_putchar('\n');
	while (list)
	{
		temp = (t_room*)list->data;
		print_room_name(temp->name, temp->x, temp->y, temp->flag);
		list = list->next;
	}
	list = e->tubes;
	while (list)
	{
		tump = (t_tube*)list->data;
		ft_putstr(tump->out1);
		ft_putchar('-');
		ft_putendl(tump->out2);
		list = list->next;
	}
	ft_putchar('\n');
}


int	main(int ac, char **av)
{
	t_env *e;

	
	(void)ac;
	(void)av;
	e = (t_env*)malloc(sizeof(t_env));
	ft_init(e);
	if (!get_map(e))
		return (ft_putstr_error("Error, bad map.\n"));
	init_ants(e);
	print_stuff(e);
	set_algo(e);
	game_loop(e);
	destroy_all(e);
	return (0);
}
