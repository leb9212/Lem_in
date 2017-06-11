/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 17:29:05 by elee              #+#    #+#             */
/*   Updated: 2016/09/26 00:38:33 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *list;

	list = *alst;
	if (list)
	{
		while (list->next)
			list = list->next;
		list->next = new;
	}
	else
		*alst = new;
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;

	ret = NULL;
	if (lst != NULL && f != NULL)
	{
		ret = NULL;
		while (lst)
		{
			ft_lstadd_back(&ret, f(lst));
			lst = lst->next;
		}
	}
	return (ret);
}
