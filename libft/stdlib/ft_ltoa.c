/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/12 22:22:22 by elee              #+#    #+#             */
/*   Updated: 2016/10/12 22:22:50 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_length(intmax_t n)
{
	int	len;
	int	index;

	len = 0;
	if (n <= 0)
		len++;
	index = n;
	while (index != 0)
	{
		index /= 10;
		len++;
	}
	return (len);
}

char		*ft_ltoa(intmax_t n)
{
	int		len;
	int		mod;
	char	*str;

	len = get_length(n);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
		str[0] = '-';
	while (len-- > 0)
	{
		mod = n % 10;
		if (mod < 0)
			mod *= -1;
		str[len] = mod + '0';
		n /= 10;
		if (n == 0)
			break ;
	}
	return (str);
}
