/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 21:08:45 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 19:51:32 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr(int n)
{
	int		ret;
	int		i;
	int		mod;
	char	revstr[10];

	ret = 0;
	ret += (n < 0) ? ft_putchar('-') : 0;
	ret += (n == 0) ? ft_putchar('0') : 0;
	i = -1;
	while (++i >= 0 && n)
	{
		mod = n % 10;
		mod *= (mod < 0) ? -1 : 1;
		revstr[i] = mod;
		n /= 10;
	}
	while (--i != -1)
		ret += ft_putchar(revstr[i] + '0');
	return (ret);
}
