/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:23:06 by elee              #+#    #+#             */
/*   Updated: 2016/11/14 21:02:44 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	merge(int *array, int *left, int *right, int count[2])
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < count[0] && j < count[1])
		array[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
	while (i < count[0])
		array[k++] = left[i++];
	while (j < count[1])
		array[k++] = right[j++];
}

void		merge_sort(int *array, int size)
{
	int		mid;
	int		i;
	int		*left;
	int		*right;
	int		count[2];

	if (size < 2)
		return ;
	mid = size / 2;
	left = (int*)malloc(sizeof(int) * mid);
	right = (int*)malloc(sizeof(int) * (size - mid));
	i = -1;
	while (++i < mid)
		left[i] = array[i];
	i = mid - 1;
	while (++i < size)
		right[i - mid] = array[i];
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	count[0] = mid;
	count[1] = size - mid;
	merge(array, left, right, count);
	free(left);
	free(right);
}
