/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:51:57 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 19:52:25 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putnbr_fd(int n, int fd)
{
	int		ret;
	int		i;
	int		mod;
	char	revstr[10];

	ret = 0;
	ret += (n < 0) ? ft_putchar_fd('-', fd) : 0;
	ret += (n == 0) ? ft_putchar_fd('0', fd) : 0;
	i = -1;
	while (++i >= 0 && n)
	{
		mod = n % 10;
		mod *= (mod < 0) ? -1 : 1;
		revstr[i] = mod;
		n /= 10;
	}
	while (--i != -1)
		ret += ft_putchar_fd(revstr[i] + '0', fd);
	return (ret);
}
