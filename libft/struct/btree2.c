/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 22:23:46 by elee              #+#    #+#             */
/*   Updated: 2016/11/25 22:53:43 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*tree;

	if (!(tree = (t_btree*)malloc(sizeof(t_btree))))
		return (NULL);
	tree->left = NULL;
	tree->right = NULL;
	tree->item = item;
	return (tree);
}

void	btree_insert(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	if (!(*root))
		*root = btree_create_node(item);
	else if (cmpf(item, (*root)->item) < 0)
		btree_insert(&(*root)->left, item, cmpf);
	else if (cmpf(item, (*root)->item) >= 0)
		btree_insert(&(*root)->right, item, cmpf);
}

void	*btree_search(t_btree *root, void *data,
		int (*cmpf)(void *, void *))
{
	if (!root)
		return (NULL);
	if (cmpf(data, root->item) < 0)
		return (btree_search(root->left, data, cmpf));
	else if (cmpf(data, root->item) > 0)
		return (btree_search(root->right, data, cmpf));
	return (root->item);
}

int		btree_max_depth(t_btree *root)
{
	if (!root)
		return (0);
	return (MAX(btree_max_depth(root->left), btree_max_depth(root->right)) + 1);
}
