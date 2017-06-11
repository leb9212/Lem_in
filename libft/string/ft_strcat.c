/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 22:21:49 by elee              #+#    #+#             */
/*   Updated: 2016/09/22 23:11:30 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int len1;
	int len2;
	int index;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	index = 0;
	while (index < len2)
	{
		s1[len1 + index] = s2[index];
		index++;
	}
	s1[len1 + index] = '\0';
	return (s1);
}
