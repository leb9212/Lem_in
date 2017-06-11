/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 20:02:06 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 14:17:57 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	int len1;
	int len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (*s1 && *s2)
	{
		if ((unsigned char)*s1 > (unsigned char)*s2)
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		else if ((unsigned char)*s1 < (unsigned char)*s2)
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		s1++;
		s2++;
	}
	if (len1 > len2)
		return ((int)((unsigned char)*(s1++)));
	else if (len1 < len2)
		return (-(int)((unsigned char)*(s2++)));
	return (0);
}
