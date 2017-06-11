/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_top_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 23:06:01 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 23:06:32 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*dl_top_back(t_dlist *list)
{
	char	*ret;

	if (list)
	{
		if (list->tail)
		{
			ret = ft_memalloc(list->tail->size);
			if (ret == NULL)
			{
				free(ret);
				return (NULL);
			}
			ft_memcpy(ret, list->tail->data, list->tail->size);
			return (ret);
		}
	}
	return (NULL);
}
