/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 14:41:40 by elee              #+#    #+#             */
/*   Updated: 2016/09/21 21:18:21 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned const char	*str;
	size_t				index;

	str = (unsigned const char*)s;
	index = 0;
	while (index < n)
	{
		if (*str == (unsigned const char)c)
			return ((void *)(s + index));
		str++;
		index++;
	}
	return (NULL);
}
