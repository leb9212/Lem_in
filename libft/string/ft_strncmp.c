/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 20:31:46 by elee              #+#    #+#             */
/*   Updated: 2016/09/21 21:19:32 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	index;

	index = 0;
	while (*s1 && *s2 && index < n)
	{
		if ((unsigned char)*s1 > (unsigned char)*s2)
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		else if ((unsigned char)*s1 < (unsigned char)*s2)
			return ((int)((unsigned char)*s1 - (unsigned char)*s2));
		s1++;
		s2++;
		index++;
	}
	if (*s1 && !(*s2) && index < n)
		return ((int)((unsigned char)*(s1++)));
	else if (!(*s1) && *s2 && index < n)
		return (-(int)((unsigned char)*(s2++)));
	else
		return (0);
}
