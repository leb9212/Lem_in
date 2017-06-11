/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:56:14 by elee              #+#    #+#             */
/*   Updated: 2016/09/30 18:39:21 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	index;

	if (s != NULL)
	{
		sub = ft_strnew(len);
		if (sub == NULL)
			return (NULL);
		index = 0;
		while (index < len)
		{
			sub[index] = s[start + index];
			index++;
		}
		sub[len] = '\0';
		return (sub);
	}
	else
		return (NULL);
}
