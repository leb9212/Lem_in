/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:52:50 by elee              #+#    #+#             */
/*   Updated: 2016/09/21 21:19:47 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	index2;
	size_t	size;

	index = 0;
	index2 = 0;
	size = 0;
	while (little[size])
		size++;
	if (size == 0)
		return ((char*)big);
	while (big[index] && (int)index <= (int)len - (int)size)
	{
		while (little[index2] == big[index + index2])
		{
			if (index2 == size - 1)
				return ((char*)(&big[index]));
			index2++;
		}
		index2 = 0;
		index++;
	}
	return (NULL);
}
