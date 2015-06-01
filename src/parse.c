/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 16:00:32 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/01 16:41:35 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.c"

/* parse = 1 si tout va bien ou si commmentaire */
static int		get_end(t_env *e)
{
	int ret;

	if ((ret = (get_next_line(0, &tmp)) > 0))
	{
		if (is_room(tmp))
		{
			stock_room(tmp, e);
			return (1);
		}
	}
	return (ft_putstr_error("Error, Wrong format for ending room.\n"));
}

static int		get_start(t_env *e)
{
	int ret;

	if ((ret = (get_next_line(0, &tmp)) > 0))
	{
		if (is_room(tmp))
		{
			stock_room(tmp, e);
			return (1);
		}
	}
	return (ft_putstr_error("Error, Wrong format for starting room.\n"));
}

static int	start_end(char *line, t_env *e)
{
	if (ft_strcmp(line, "start"))
	{
		if (!e->start)
		{
			get_start(e);
			return (1);
		}
		else
			return (ft_putstr_error("Error, multiple start.\n"));
	}
	else if (ft_strcmp(line, "end"))
	{
		if (!e->end)
		{
			get_end(e);
			return (1);
		}
		else
			return (ft_putstr_error("Error, multiple start.\n"));
	}
	else
		return (ft_putstr("Error, bad comment.\n"));
}

int	parse(t_env *e, char *line, int ret)
{
	char *temp;

	if (line[0] == '#')
	{
		if (line[1] == '#')
			return(start_end(&(line(line[2])), e));
		else
			return (1):
	}
	else if (ft_isnum(line[0]))
	{
		if (is_room(line))
			return (stock_room(line, e));
		else if (is_tube(line))
			return (stock_tube(line, e));
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

