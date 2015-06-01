/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trijoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jwalle <jwalle@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 12:05:30 by jwalle            #+#    #+#             */
/*   Updated: 2015/05/21 15:47:30 by jwalle           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_trijoin(char *s1, char *s2, char *s3)
{
	char	*ret;
	char	*temp;

	temp = ft_strjoin(s1, s2);
	ret = ft_strjoin(temp, s3);
	free(temp);
	return (ret);
}
