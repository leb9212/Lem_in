/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_push_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:53:53 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 22:47:32 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_push_back(t_dlist *dlist, void *data, size_t size)
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
	dlist->tail->next = new_node;
	new_node->prev = dlist->tail;
	dlist->tail = new_node;
}
