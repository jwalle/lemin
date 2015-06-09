/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 16:00:32 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/01 20:14:01 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/* parse = 1 si tout va bien ou si commmentaire */

static int		get_end(t_env *e)
{
	int 	ret;
	char	*tmp;

	if ((ret = (get_next_line(0, &tmp)) > 0))
	{
		if (is_room(tmp))
		{
			/*stock_room(tmp, e);*/
			e->rooms = ft_lst_push(e->rooms ,stock_room(tmp, e, END));
			return (1);
		}
	}
	return (ft_putstr_error("Error, Wrong format for ending room.\n"));
}

static int		get_start(t_env *e)
{
	int		ret;
	char	*tmp;

	if ((ret = (get_next_line(0, &tmp)) > 0))
	{
		printf("start = %s\n", tmp);
		if (is_room(tmp))
		{
			/*stock_room(tmp, e);*/
			e->rooms = ft_lst_push(e->rooms ,stock_room(tmp, e, START));
			return (1);
		}
	}
	return (ft_putstr_error("Error, Wrong format for starting room.\n"));
}

static int	start_end(char *line, t_env *e)
{
	printf("##== Start_end ==#\n");
	if (!ft_strcmp(line, "start"))
	{
		if (!e->start)
		{
			get_start(e);
			e->start = 1;
			return (1);
		}
		else
			return (ft_putstr_error("Error, multiple start.\n"));
	}
	else if (!ft_strcmp(line, "end"))
	{
		if (!e->end)
		{
			get_end(e);
			e->end = 1;
			return (1);
		}
		else
			return (ft_putstr_error("Error, multiple end.\n"));
	}
	else
		return (ft_putstr_error("Error, bad comment.\n"));
}

int	parse(t_env *e, char *line, int ret)
{
	printf("##== Parse ==#\n");
	(void)ret;
	if (line[0] == '#')
	{
		if (line[1] == '#')
			return(start_end(&(line[2]), e));
		else
			return (1);
	}
	else if (ft_isdigit(line[0]))
	{
		if (is_room(line))
			e->rooms = ft_lst_push(e->rooms ,stock_room(line, e, NORMAL));
		else if (is_tube(line))
			e->tubes = ft_lst_push(e->tubes, stock_tube(line));
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

