/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 20:35:21 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:45 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putdi(intmax_t n, int fl[8])
{
	int		i;
	int		mod;
	char	revstr[19];

	if (n == (intmax_t)9223372036854775808U && fl[7])
		ft_putstr("9,223,372,036,854,775,808");
	if (n == (intmax_t)9223372036854775808U && !fl[7])
		ft_putstr("9223372036854775808");
	if (n == (intmax_t)9223372036854775808U)
		return ;
	i = -1;
	(n == 0) ? ft_putchar('0') : 0;
	while (++i >= 0 && n != 0)
	{
		mod = n % 10;
		mod *= (mod < 0) ? -1 : 1;
		revstr[i] = mod;
		n /= 10;
	}
	while (--i != -1)
	{
		ft_putchar(revstr[i] + '0');
		(fl[7] && i % 3 == 0 && i > 0) ? ft_putchar(',') : 0;
	}
}

void	ft_putu(size_t n, int fl[8])
{
	int		i;
	int		mod;
	char	revstr[19];

	i = -1;
	if (n == 0)
		ft_putchar('0');
	while (++i >= 0 && n != 0)
	{
		mod = n % 10;
		revstr[i] = mod;
		n /= 10;
	}
	while (--i != -1)
	{
		ft_putchar(revstr[i] + '0');
		(fl[7] && i % 3 == 0 && i > 0) ? ft_putchar(',') : 0;
	}
}

void	ft_putb(size_t n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n < 2)
		ft_putchar(n + '0');
	else if (n >= 2)
	{
		ft_putb(n / 2);
		ft_putchar(n % 2 + '0');
	}
}

void	ft_puto(size_t n)
{
	if (n == 0)
		ft_putchar('0');
	else if (n < 8)
		ft_putchar(n + '0');
	else if (n >= 8)
	{
		ft_puto(n / 8);
		ft_putchar(n % 8 + '0');
	}
}

void	ft_putx(size_t n, char spec)
{
	if (n >= 16)
		ft_putx(n / 16, spec);
	if (n % 16 < 10)
		ft_putchar((n % 16) + '0');
	else
		ft_putchar((n % 16) - 10 + ((spec == 'x') ? 'a' : 'A'));
}
