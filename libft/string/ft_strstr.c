/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:35:40 by elee              #+#    #+#             */
/*   Updated: 2016/09/21 21:20:03 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
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
	while (big[index])
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
