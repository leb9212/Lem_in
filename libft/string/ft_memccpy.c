/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 20:38:18 by elee              #+#    #+#             */
/*   Updated: 2016/09/30 16:34:45 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	*copy;
	size_t			index;

	str = (unsigned char*)dst;
	copy = (unsigned char*)src;
	index = 0;
	while (index < n)
	{
		str[index] = copy[index];
		if (copy[index] == (unsigned char)c)
			return ((void*)&str[index + 1]);
		index++;
	}
	return (NULL);
}
