/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_top_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:40:18 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 23:04:11 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*dl_top_front(t_dlist *list)
{
	char	*ret;

	if (list)
	{
		if (list->head)
		{
			ret = ft_memalloc(list->head->size);
			if (ret == NULL)
			{
				free(ret);
				return (NULL);
			}
			ft_memcpy(ret, list->head->data, list->head->size);
			return (ret);
		}
	}
	return (NULL);
}
