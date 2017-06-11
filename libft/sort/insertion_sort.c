/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 20:10:11 by elee              #+#    #+#             */
/*   Updated: 2016/11/14 21:02:24 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	insertion_sort(int *array, int size)
{
	int		i;
	int		j;
	int		key;

	i = 0;
	while (++i < size)
	{
		key = array[i];
		j = i;
		while (--j >= 0 && array[j] > key)
			array[j + 1] = array[j];
		array[j + 1] = key;
	}
}
