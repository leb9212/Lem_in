/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:13:56 by elee              #+#    #+#             */
/*   Updated: 2016/11/14 21:02:32 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	min_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void		selection_sort(int *array, int size)
{
	int		i;
	int		j;
	int		min_idx;

	i = -1;
	while (++i < size - 1)
	{
		min_idx = i;
		j = i;
		while (++j < size)
			if (array[j] < array[min_idx])
				min_idx = j;
		min_swap(&array[min_idx], &array[i]);
	}
}
