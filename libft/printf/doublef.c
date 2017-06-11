/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublef.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:29:15 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:41:51 by elee             ###   ########.fr       */
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
	if (i == 0.0)
		return (0);
	if (i < 1.0)
		while ((f *= 10.0) < 1.0)
			power--;
	else
		while ((i /= 10.0) >= 1.0)
			power++;
	return (power);
}

static int	f_preformat(double n, int fl[8], int len)
{
	int		index;
	int		ret;

	ret = 0;
	ret += (fl[3] && is_neg(n) && !is_in(n)) ? ft_putchar('-') : 0;
	ret += (fl[3] && fl[5] && !is_neg(n) && !is_in(n))
		? ft_putchar('+') : 0;
	ret += (fl[3] && fl[6] && !fl[5] && !is_neg(n) && !is_in(n))
		? ft_putchar(' ') : 0;
	if (!fl[4] && len + (fl[1] > 0) + fl[1] < fl[0])
	{
		index = ((n != n && is_neg(n)) || fl[5] || fl[6]) ? 0 : -1;
		index += (fl[2] && !fl[1] && !is_in(n)) ? 1 : 0;
		while (++index < fl[0] - len - (fl[1] > 0) - fl[1])
			ret += (!is_in(n) && fl[3]) ? ft_putchar('0') : ft_putchar(' ');
	}
	ret += (is_neg(n) && n == n &&
			(!fl[3] || is_in(n))) ? ft_putchar('-') : 0;
	ret += (!is_neg(n) && n == n && fl[5] &&
			(!fl[3] || is_in(n))) ? ft_putchar('+') : 0;
	ret += (!is_neg(n) && n == n && fl[6] && !fl[5] &&
			(!fl[3] || is_in(n))) ? ft_putchar(' ') : 0;
	return (ret);
}

static int	f_postformat(double n, int fl[8], int len)
{
	int		index;
	int		ret;

	ret = 0;
	if (fl[4] && len + (fl[1] > 0) + fl[1] < fl[0])
	{
		index = ((n != n && is_neg(n)) || fl[5] || fl[6]) ? 0 : -1;
		index += (fl[2] && !fl[1] && !is_in(n)) ? 1 : 0;
		while (++index < fl[0] - len - (fl[1] > 0) - fl[1])
			ret += ft_putchar(' ');
		return (ret);
	}
	return (0);
}

static int	f_infnan(double n, int fl[8], char *s)
{
	int		ret;

	ret = 0;
	if (n != n || (n == 1.0 / 0.0) || (n == -1.0 / 0.0))
	{
		fl[1] = 0;
		ret += f_preformat(n, fl, 3);
		if (n != n)
			ret += (ft_islower(*(s + mp(s)))) ? ft_putstr("nan")
				: ft_putstr("NAN");
		else if (n == 1.0 / 0.0 || n == -1.0 / 0.0)
			ret += (ft_islower(*(s + mp(s)))) ? ft_putstr("inf")
				: ft_putstr("INF");
		ret += f_postformat(n, fl, 3);
	}
	return (ret);
}

int			ft_putf(double n, int fl[8], char *s)
{
	double		i;
	double		f;
	int			ret;
	int			k;

	if ((ret = f_infnan(n, fl, s)))
		return (ret);
	fl[1] = (fl[1] == -1) ? 6 : fl[1];
	f = ft_rint(ft_modf(n, &i) * ft_pb(fl[1], 10));
	((k = -1) && f < 0) ? f *= -1 : 0;
	(i < 0) ? i *= -1 : 0;
	ret += f_preformat(n, fl, ft_gp(n) + 1);
	while (++k <= ft_gp(n))
	{
		ret += ft_putchar((int)(i / ft_pb((ft_gp(n) - k), 10)) + '0');
		i -= (int)(i / ft_pb((ft_gp(n) - k), 10)) * ft_pb((ft_gp(n) - k), 10);
	}
	ret += (fl[1] || fl[2]) ? ft_putchar('.') : 0;
	ret += g_loop(f, fl, s);
	ret += f_postformat(n, fl, ft_gp(n) + 1);
	return (ret);
}
