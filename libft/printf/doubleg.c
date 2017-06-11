/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubleg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:30:21 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:41:55 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_gp(double n)
{
	int		power;
	double	f;
	double	i;

	power = 0;
	f = ft_modf(n, &i);
	f = (f < 0) ? -f : f;
	i = (i < 0) ? -i : i;
	if (i < 1.0)
		while ((f *= 10.0) < 1.0)
			power--;
	else
		while ((i /= 10.0) >= 1.0)
			power++;
	return (power);
}

int			g_loop(double f, int fl[8], char *s)
{
	int		ret;
	int		k;
	int		count;

	ret = 0;
	k = 0;
	count = 0;
	while (++k <= fl[1])
	{
		if (ft_tolower((*(s + mp(s))) == 'g') && !fl[2])
		{
			if ((int)(f / ft_pb((fl[1] - k), 10)) == 0)
				count++;
			else
			{
				while (count-- > 0)
					ret += ft_putchar('0');
				ret += ft_putchar((int)(f / ft_pb((fl[1] - k), 10)) + '0');
			}
		}
		else
			ret += ft_putchar((int)(f / ft_pb((fl[1] - k), 10)) + '0');
		f -= (int)(f / ft_pb((fl[1] - k), 10)) * ft_pb((fl[1] - k), 10);
	}
	return (ret);
}

int			ft_putg(double n, int fl[8], char *s)
{
	fl[1] = (fl[1] == -1) ? 6 : fl[1];
	fl[1] = (fl[1] == 0) ? 1 : fl[1];
	if (ft_gp(n) < -3 || ft_gp(n) >= fl[1])
		return (ft_pute(n, fl, s));
	else
		return (ft_putf(n, fl, s));
}
