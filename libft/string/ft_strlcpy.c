/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 23:52:20 by elee              #+#    #+#             */
/*   Updated: 2016/09/25 23:37:03 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t src_len;
	size_t index;

	if (dest == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	index = 0;
	while ((int)index < (int)(size - 1) && src[index])
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = '\0';
	return (src_len);
}
