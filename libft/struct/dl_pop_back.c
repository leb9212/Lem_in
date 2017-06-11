/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_pop_back.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 23:09:59 by elee              #+#    #+#             */
/*   Updated: 2016/09/25 17:27:32 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*dl_pop_back(t_dlist *list, void (*del)(void *, size_t))
{
	void	*data;
	t_node	*temp;

	data = dl_top_back(list);
	if (list && del)
		if (list->tail)
		{
			temp = list->tail;
			list->tail = list->tail->prev;
			if (list->tail != NULL)
				list->tail->next = NULL;
			else
				list->head = NULL;
			delete_node(&temp, del);
		}
	return (data);
}
