/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 22:32:26 by elee              #+#    #+#             */
/*   Updated: 2016/09/22 23:11:57 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	len1;
	size_t	index;

	len1 = ft_strlen(s1);
	index = 0;
	while (index < n && s2[index])
	{
		s1[len1 + index] = s2[index];
		index++;
	}
	s1[len1 + index] = '\0';
	return (s1);
}
