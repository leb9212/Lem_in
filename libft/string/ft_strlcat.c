/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 23:50:00 by elee              #+#    #+#             */
/*   Updated: 2016/09/22 19:43:37 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len1;
	size_t	len2;
	size_t	index;

	len1 = ft_strlen(dst);
	len2 = ft_strlen(src);
	index = 0;
	while ((int)index < ((int)size - (int)len1 - 1) && src[index])
	{
		dst[len1 + index] = src[index];
		index++;
	}
	dst[len1 + index] = '\0';
	if (size < len1)
		return (size + len2);
	else
		return (len1 + len2);
}
