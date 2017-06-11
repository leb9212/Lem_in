/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 22:50:21 by elee              #+#    #+#             */
/*   Updated: 2016/10/04 22:52:59 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		*ft_intnew(int num)
{
	int		*array;
	int		index;

	array = (int*)malloc(sizeof(int) * num);
	if (array == NULL)
		return (NULL);
	index = 0;
	while (index < num)
	{
		array[index] = 0;
		index++;
	}
	return (array);
}
