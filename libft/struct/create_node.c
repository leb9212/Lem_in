/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:51:43 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 21:51:52 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_node	*create_node(void *data, size_t size)
{
	t_node	*node;

	node = (t_node*)malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	if (data == NULL)
	{
		node->data = NULL;
		node->size = size;
	}
	else
	{
		node->data = ft_memalloc(size);
		if (node->data == NULL)
		{
			free(node);
			return (NULL);
		}
		ft_memcpy(node->data, data, size);
		node->size = size;
	}
	node->next = NULL;
	node->prev = NULL;
	return (node);
}
