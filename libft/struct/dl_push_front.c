/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_push_front.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:53:20 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 21:53:27 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_push_front(t_dlist *dlist, void *data, size_t size)
{
	t_node	*new_node;

	new_node = create_node(data, size);
	if (new_node == NULL)
		return ;
	if (dlist->head == NULL)
	{
		dlist->head = new_node;
		dlist->tail = new_node;
		return ;
	}
	dlist->head->prev = new_node;
	new_node->next = dlist->head;
	dlist->head = new_node;
}
