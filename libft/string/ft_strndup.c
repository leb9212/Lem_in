/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 00:25:08 by elee              #+#    #+#             */
/*   Updated: 2016/09/26 00:26:57 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char	*copy;
	size_t	index;

	copy = (char*)malloc(sizeof(char) * (n + 1));
	if (copy == NULL)
		return (NULL);
	index = 0;
	while (index < n)
	{
		copy[index] = s1[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}
