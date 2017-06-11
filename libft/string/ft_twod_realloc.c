/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_twod_realloc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:57:06 by elee              #+#    #+#             */
/*   Updated: 2016/12/09 14:00:17 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_twod_realloc(char ***map, char *line)
{
	int		len;
	char	**new;
	int		index;

	len = ft_ptrlen(*map);
	new = ft_ptrnew(len);
	index = -1;
	while (++index < len)
		new[index] = ft_strdup((*map)[index]);
	ft_free_two(*map);
	*map = ft_ptrnew(len + 1);
	index = -1;
	while (++index < len)
		(*map)[index] = ft_strdup(new[index]);
	(*map)[index] = ft_strdup(line);
	ft_free_two(new);
	return (1);
}
