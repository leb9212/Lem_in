/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/21 16:24:52 by elee              #+#    #+#             */
/*   Updated: 2016/09/21 21:19:54 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	if ((char)c == '\0')
		return ((char*)(s + len));
	while (len != 0)
	{
		if (s[len - 1] == (char)c)
			return ((char*)(s + len - 1));
		len--;
	}
	return (NULL);
}
