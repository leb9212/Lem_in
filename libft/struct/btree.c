/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:13:11 by elee              #+#    #+#             */
/*   Updated: 2016/11/25 23:00:03 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		btree_apply_pre(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	f(root->item);
	btree_apply_pre(root->left, f);
	btree_apply_pre(root->right, f);
}

void		btree_apply_in(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	btree_apply_in(root->left, f);
	f(root->item);
	btree_apply_in(root->right, f);
}

void		btree_apply_post(t_btree *root, void (*f)(void *))
{
	if (!root)
		return ;
	btree_apply_post(root->left, f);
	btree_apply_post(root->right, f);
	f(root->item);
}

static void	apply_by_level(t_btree *root, int current_level, int level,
		void (*f)(void *item, int current_level, int is_first))
{
	if (!root)
		return ;
	if (level == current_level)
		f(root->item, current_level, 0);
	else
	{
		apply_by_level(root->left, current_level + 1, level, f);
		apply_by_level(root->right, current_level + 1, level, f);
	}
}

void		btree_apply_breadth(t_btree *root,
		void (*f)(void *item, int current_level, int is_first))
{
	int		i;
	int		j;

	i = btree_max_depth(root);
	j = -1;
	while (j++ < i)
		apply_by_level(root, 0, j, f);
}
