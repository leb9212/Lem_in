/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:39:16 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 18:30:28 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			fresh[index] = f(index, s[index]);
			index++;
		}
		return (fresh);
	}
	return (NULL);
}
