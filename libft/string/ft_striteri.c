/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 20:23:52 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 14:21:01 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	length;
	size_t	index;

	if (s != NULL && f != NULL)
	{
		length = ft_strlen(s);
		index = 0;
		while (index < length)
		{
			f(index, &s[index]);
			index++;
		}
	}
}
