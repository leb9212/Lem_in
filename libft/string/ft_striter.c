/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:54:17 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 14:20:36 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striter(char *s, void (*f)(char *))
{
	size_t	length;
	size_t	index;

	if (s != NULL && f != NULL)
	{
		length = ft_strlen(s);
		index = 0;
		while (index < length)
		{
			f(&s[index]);
			index++;
		}
	}
}
