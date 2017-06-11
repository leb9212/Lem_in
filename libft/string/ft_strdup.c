/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 10:01:08 by elee              #+#    #+#             */
/*   Updated: 2016/09/26 00:25:50 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*copy;
	int		len;
	int		index;

	len = ft_strlen(s1);
	copy = (char*)malloc(sizeof(char) * (len + 1));
	if (copy == NULL)
		return (NULL);
	index = 0;
	while (s1[index])
	{
		copy[index] = s1[index];
		index++;
	}
	copy[index] = '\0';
	return (copy);
}
