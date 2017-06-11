/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 21:22:35 by elee              #+#    #+#             */
/*   Updated: 2016/09/25 23:22:00 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strlowcase(char *str)
{
	int		index;

	if (str == NULL)
		return (NULL);
	index = 0;
	while (str[index])
	{
		if (str[index] >= 65 && str[index] <= 90)
			str[index] += 32;
		index++;
	}
	return (str);
}
