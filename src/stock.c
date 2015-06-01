/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 17:22:31 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/01 18:00:14 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

//attention double espace, etc...

int		is_room(char *line)
{
	int i;
	int n;

	i = 0;
	n = 0;
	while (line[i] != '\n')
	{
		if (line[i] == ' ' || line[i] == '\n')
			n++;
		else if (!ft_isdigit(line[i]))
			return (0);
		i++;
	}
	printf("room, n = %d\n", n);
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
	while (line[i] != '\n')
	{
		if (line[i] == '-')
			n++;
		else if (!ft_isdigit(line[i]) && line[i] != '\n')
			return (0);
		i++;
	}
	printf("tube, n = %d\n", n);
	if (n == 1)
		return (1);
	return (0);
}

int		stock_room(char *line, t_env *e)
{
	printf("stock = %s, %d\n", line, e->start);
	return (1);
}

int		stock_tube(char *line, t_env *e)
{
	printf("stock = %s, %d\n", line, e->start);
	return (1);
}
