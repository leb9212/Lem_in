/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heap_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:34:05 by elee              #+#    #+#             */
/*   Updated: 2016/11/14 21:02:58 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	max_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	heapify(int *array, int i, int size)
{
	int	max;
	int	l;
	int	r;

	max = i;
	l = i * 2 + 1;
	r = i * 2 + 2;
	if (l < size && array[l] > array[max])
		max = l;
	if (r < size && array[r] > array[max])
		max = r;
	if (max != i)
	{
		max_swap(&array[i], &array[max]);
		heapify(array, max, size);
	}
}

void		heap_sort(int *array, int size)
{
	int		i;

	i = size / 2;
	while (--i >= 0)
		heapify(array, i, size);
	i = size;
	while (--i >= 0)
	{
		max_swap(&array[0], &array[i]);
		heapify(array, 0, i);
	}
}
