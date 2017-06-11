/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_chr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 18:36:34 by elee              #+#    #+#             */
/*   Updated: 2016/09/28 18:39:36 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_count_chr(char *str, char c)
{
	int		index;
	size_t	size;

	if (str == NULL)
		return (0);
	index = -1;
	size = 0;
	while (str[++index] != '\0')
		if (str[index] == c)
			size++;
	return (size);
}
