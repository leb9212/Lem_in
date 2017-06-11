/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_size.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 17:35:20 by elee              #+#    #+#             */
/*   Updated: 2016/09/25 17:39:00 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	dl_size(t_dlist *dlist)
{
	t_node	*node;
	size_t	size;

	size = 0;
	if (dlist == NULL)
		return (0);
	node = dlist->head;
	if (node == NULL)
		return (0);
	while (node != NULL)
	{
		size++;
		node = node->next;
	}
	return (size);
}
