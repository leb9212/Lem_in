/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_pop_front.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:49:18 by elee              #+#    #+#             */
/*   Updated: 2016/09/25 23:39:01 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*dl_pop_front(t_dlist *list, void (*del)(void *, size_t))
{
	void	*data;
	t_node	*temp;

	data = dl_top_front(list);
	if (list && del)
		if (list->head)
		{
			temp = list->head;
			list->head = list->head->next;
			if (list->head != NULL)
				list->head->prev = NULL;
			else
				list->tail = NULL;
			delete_node(&temp, del);
		}
	return (data);
}
