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

//attention double espace, etc...

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
	printf("is room = %s\n", line);
	while (line[i] != '\0')
	{
		if (line[i] == ' ')
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
	while (line[i] != '\0')
	{
		if (line[i] == '-')
			n++;
		else if (!ft_isdigit(line[i]))
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
	printf("stock room : %s, %d\n", line, e->start);
	return (1);
}

int		stock_tube(char *line, t_env *e)
{
	printf("stock tube : %s, %d\n", line, e->start);
	return (1);
}
