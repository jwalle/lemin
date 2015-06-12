/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 17:22:31 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/01 20:16:52 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*attention double espace, etc...*/

int		is_comment(char *line)
{
	if (line[0] == '#' && line[1] && line[1] != '#')
		return (1);
	return (0);
}	

int		is_room(char *line)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
			n++;
		else if (!ft_isalnum(line[i]))
			return (0);
		i++;
	}
	if (n == 2)
		return (1);
	return (0);
}

int		is_tube(char *line)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			n++;
		else if (!ft_isalnum(line[i]))
			return (0);
		i++;
	}
	if (n == 1)
		return (1);
	return (0);
}

t_room 	*stock_room(char *line,t_env *e, int flag)
{
	t_room *new;
	int i;

	i = 0;
	(void)e;
	if (!(new = malloc(sizeof(t_room))))
		return (NULL);
	new->flag = flag;
	while (line[i] != ' ')
		i++;
	new->name = ft_strsub(line, 0, i);
	while (line[i] == ' ')
		i++;
	new->x = ft_atoi(line + i);
	while (line[i] != ' ')
		i++;
	while (line[i] == ' ')
		i++;
	new->y = ft_atoi(line + i);
	new->full = 0;
	new->find = 0;
	return (new);
}

t_tube	*stock_tube(char *line)
{
	t_tube *new;
	int i;

	i = 0;
	if (!(new = malloc(sizeof(t_tube))))
		return (NULL);
	while (line[i] != '-')
		i++;
	new->out1 = ft_strsub(line, 0, i);
	i++;
	new->out2 = ft_strdup(line + i);
	new->visited = 0;
	return (new);
}
