/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 19:46:07 by elee              #+#    #+#             */
/*   Updated: 2016/11/14 22:24:07 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	partition(int *array, int l, int r)
{
	int		i;
	int		j;
	int		temp;

	i = l;
	j = r + 1;
	while (1)
	{
		i++;
		while (array[i] <= array[l] && i <= r)
			i++;
		j--;
		while (array[j] > array[l] && j >= l)
			j--;
		if (i >= j)
			break ;
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	temp = array[l];
	array[l] = array[j];
	array[j] = temp;
	return (j);
}

void		quick_sort(int *array, int l, int r)
{
	int	j;

	if (l < r)
	{
		j = partition(array, l, r);
		quick_sort(array, l, j - 1);
		quick_sort(array, j + 1, r);
	}
}
