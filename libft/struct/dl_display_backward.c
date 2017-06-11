/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_display_backward.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 21:55:12 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 21:55:13 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	dl_display_backward(t_dlist *dlist)
{
	t_node	*last;

	last = dlist->tail;
	while (last != NULL)
	{
		ft_putendl(last->data);
		last = last->prev;
	}
}
