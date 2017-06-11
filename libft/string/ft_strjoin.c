/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 23:10:46 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 18:30:43 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, const char *s2)
{
	int		len1;
	int		len2;
	char	*join;
	int		index;

	if (s1 != NULL && s2 != NULL)
	{
		len1 = ft_strlen(s1);
		len2 = ft_strlen(s2);
		join = (char*)malloc(sizeof(char) * (len1 + len2 + 1));
		if (join == NULL)
			return (NULL);
		index = -1;
		while (++index < len1)
			join[index] = s1[index];
		index = -1;
		while (++index < len2)
			join[len1 + index] = s2[index];
		join[len1 + index] = '\0';
		return (join);
	}
	else
		return (NULL);
}
