/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_display_forward.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:54:32 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 21:54:32 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_display_forward(t_dlist *dlist)
{
	t_node	*first;

	first = dlist->head;
	while (first != NULL)
	{
		ft_putendl(first->data);
		first = first->next;
	}
}
