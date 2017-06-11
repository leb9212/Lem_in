/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inf_nan.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 22:17:22 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:20 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_neg(double n)
{
	unsigned long long *i;

	i = (unsigned long long *)&n;
	return ((*i >> 63) & 1);
}

int		is_zero(double n)
{
	unsigned long long	*i;
	unsigned short		exponent;
	unsigned long long	fraction;

	i = (unsigned long long *)&n;
	exponent = (unsigned short)(*i >> 52 & 0x7FF);
	fraction = *i & 0x000FFFFFFFFFFFFFULL;
	return ((exponent == 0 && fraction == 0) ? 1 : 0);
}

int		is_in(double n)
{
	return ((n != n || (n == 1.0 / 0.0) || (n == -1.0 / 0.0)));
}

int		get_exponent(double n)
{
	unsigned long long	*i;
	unsigned short		exponent;

	i = (unsigned long long *)&n;
	exponent = (unsigned short)(*i >> 52 & 0x7FF);
	return ((int)exponent - 1023);
}

int		ft_sci(double *i, double *f, int power, int fl[8])
{
	if ((int)(*i) == 0)
	{
		power -= 1;
		*i = (int)(*f / ft_pb((fl[1] - 1), 10));
		*f -= (int)(*f / ft_pb(fl[1] - 1, 10)) * ft_pb(fl[1] - 1, 10);
		*f *= 10.0;
	}
	return (power);
}
