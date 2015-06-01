/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/01 14:41:15 by jwalle            #+#    #+#             */
/*   Updated: 2015/06/01 18:07:54 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include <stdio.h>

void	ft_init(t_env *e)
{
	e->i = 0;
	e->start = 0;
	e->end = 0;
}

int		get_map(t_env *e)
{
	char	*tmp;
	int		ret;

	while ((ret = (get_next_line(0, &tmp)) > 0))
	{
		parse(e, tmp, ret);
		printf("gnl = %d, %s\n",e->i , tmp);
		free(tmp);
	}
	if (!ret)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_env *e;

	e = (t_env*)malloc(sizeof(t_env));
	ft_init(e);
	printf("%d, %s\n", ac, av[1]);
	get_map(e);
	return (0);
}
