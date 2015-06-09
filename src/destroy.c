/* ---- HEADER ---- */

#include "lemin.h"

void destroy_ant(void *data)
{
/*	t_ant *ant;

	ant = (t_ant*)data;
*/
	free(data);
	data = NULL;
}

void destroy_tube(void *data)
{
	t_tube *tube;

	tube = (t_tube*)data;
	ft_strdel(&tube->out1);
	ft_strdel(&tube->out2);
	free(data);
	data = NULL;
}

void destroy_room(void *data)
{
	t_room *room;

	room = (t_room*)data;
	ft_strdel(&room->name);
	free(data);
	data = NULL;
}

void destroy_all(t_env *e)
{
	t_list *rooms;
	t_list *tubes;
	t_list *ants;

	rooms = e->rooms;
	if (rooms)
	{
		ft_lst_foreach(rooms, destroy_room);
		ft_lst_rec_free(rooms);
	}
	tubes = e->tubes;
	if (tubes)
	{
		ft_lst_foreach(tubes, destroy_tube);
		ft_lst_rec_free(tubes);
	}
	ants = e->ants;
	if (ants)
	{
		ft_lst_foreach(ants, destroy_ant);
		ft_lst_rec_free(ants);
	}
	free(e);
}
