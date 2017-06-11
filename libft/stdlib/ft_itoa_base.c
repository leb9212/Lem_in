/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:20:37 by elee              #+#    #+#             */
/*   Updated: 2016/09/26 00:36:36 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(int value, int base)
{
	int		len;
	int		index;

	len = 0;
	if (base == 10 && value < 0)
		len++;
	if (value == 0)
		len++;
	index = value;
	while (index != 0)
	{
		index /= base;
		len++;
	}
	return (len);
}

char		*ft_itoa_base(int value, int base)
{
	int		len;
	int		index;
	char	*str;

	if (base < 2 || base > 16)
		return (0);
	len = get_length(value, base);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (base == 10 && value < 0)
		str[0] = '-';
	str[len] = '\0';
	while (len-- > 0)
	{
		index = value % base;
		if (index < 0)
			index = -index;
		if (index > 9)
			str[len] = index + 'A' - 10;
		else
			str[len] = index + '0';
		value /= base;
		if (value == 0)
			break ;
	}
	return (str);
}
