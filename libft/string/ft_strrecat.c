/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrecat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 23:12:13 by elee              #+#    #+#             */
/*   Updated: 2016/11/01 23:12:47 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrecat(char *lines, char *input)
{
	size_t	len1;
	size_t	len2;
	char	*tmp;

	if (lines == NULL)
	{
		len2 = ft_strlen(input);
		lines = ft_strnew(len2);
		ft_strncpy(lines, input, len2);
	}
	else
	{
		len1 = ft_strlen(lines);
		len2 = ft_strlen(input);
		tmp = ft_strdup(lines);
		free(lines);
		lines = ft_strnew(len1 + len2);
		ft_strncpy(lines, tmp, len1);
		ft_bzero(tmp, len1);
		free(tmp);
		ft_strlcat(lines, input, len1 + len2 + 1);
	}
	return (lines);
}
