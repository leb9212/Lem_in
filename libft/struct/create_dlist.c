/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_dlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 22:03:26 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 22:16:35 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist	*create_dlist(void)
{
	t_dlist	*dlist;

	dlist = (t_dlist*)malloc(sizeof(t_dlist));
	if (dlist == NULL)
		return (NULL);
	dlist->head = NULL;
	dlist->tail = NULL;
	return (dlist);
}
