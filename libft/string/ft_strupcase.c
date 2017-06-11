/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 21:11:26 by elee              #+#    #+#             */
/*   Updated: 2016/09/25 23:21:52 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strupcase(char *str)
{
	int		index;

	if (str == NULL)
		return (NULL);
	index = 0;
	while (str[index])
	{
		if (str[index] >= 97 && str[index] <= 122)
			str[index] -= 32;
		index++;
	}
	return (str);
}
