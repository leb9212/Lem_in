/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_node.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:56:36 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 22:00:35 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delete_node(t_node **node_ptr, void (*del)(void *, size_t))
{
	if (*node_ptr != NULL)
	{
		del((*node_ptr)->data, (*node_ptr)->size);
		free(*node_ptr);
		*node_ptr = NULL;
	}
}
