/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_dlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:06:20 by elee              #+#    #+#             */
/*   Updated: 2016/09/25 17:00:58 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delete_dlist(t_dlist **dlist_ptr, void (*del)(void *, size_t))
{
	t_node	*node;
	t_node	*temp;

	if (*dlist_ptr && del)
	{
		node = (*dlist_ptr)->head;
		while (node)
		{
			temp = node;
			node = node->next;
			del(temp->data, temp->size);
			free(node);
		}
		free(*dlist_ptr);
		*dlist_ptr = NULL;
	}
}
