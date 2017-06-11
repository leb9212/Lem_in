/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 10:32:31 by elee              #+#    #+#             */
/*   Updated: 2016/10/07 17:22:05 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*str1;
	unsigned const char	*str2;

	str1 = (unsigned char*)dst;
	str2 = (unsigned const char*)src;
	if (str2 < str1)
		while ((int)(len--) > 0)
			*(str1 + len) = *(str2 + len);
	else if (str2 > str1)
		while ((int)(len--) > 0)
			*str1++ = *str2++;
	return (dst);
}
