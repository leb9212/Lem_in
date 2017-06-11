/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:37:16 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 18:30:13 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	length;
	char	*fresh;
	size_t	index;

	if (s != NULL && f != NULL)
	{
		length = ft_strlen(s);
		fresh = ft_strnew(length);
		if (fresh == NULL)
			return (NULL);
		index = 0;
		while (index < length)
		{
			fresh[index] = (*f)(s[index]);
			index++;
		}
		return (fresh);
	}
	return (NULL);
}
