/* ---- HEADER ----- */

#include "lemin.h"

t_ant 	*stock_ant(t_env *e, int id)
{
	t_ant *new;

	if (!(new = malloc(sizeof(t_ant))))
		return (NULL);
	new->id = id;
	new->as_moved = 0;
	new->room = get_start_room(e);
	new->previous = NULL;
	new->flag = START;
	return (new);
}

int init_ants(t_env *e)
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

