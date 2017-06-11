/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublee.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:29:09 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:41:48 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int	g_fl[8];

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

static int	e_preformat(double n, int fl[8], int ex)
{
	int		index;
	int		ret;

	ex = (ex > 0) ? ex : 0;
	ret = 0;
	ret += (fl[3] && is_neg(n) && !is_in(n)) ? ft_putchar('-') : 0;
	ret += (fl[3] && fl[5] && !is_neg(n) && !is_in(n))
		? ft_putchar('+') : 0;
	ret += (fl[3] && fl[6] && !fl[5] && !is_neg(n) && !is_in(n))
		? ft_putchar(' ') : 0;
	if (!fl[4] && fl[1] + 6 + ex < fl[0] + (fl[1] == 0))
	{
		index = ((n != n && is_neg(n)) || fl[5] || fl[6]) ? 0 : -1;
		index += (fl[2] && !fl[1] && !is_in(n)) ? 1 : 0;
		while (++index < fl[0] + (fl[1] == 0) - fl[1] - 6 - ex)
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

static int	e_postformat(double n, int fl[8], int ex)
{
	int		index;
	int		ret;

	ex = (ex > 0) ? ex : 0;
	ret = 0;
	if (fl[4] && fl[1] + 6 + ex < fl[0] + (fl[1] == 0))
	{
		index = ((n != n && is_neg(n)) || fl[5] || fl[6]) ? 0 : -1;
		index += (fl[2] && !fl[1] && !is_in(n)) ? 1 : 0;
		while (++index < fl[0] + (fl[1] == 0) - fl[1] - 6 - ex)
			ret += ft_putchar(' ');
	}
	return (ret);
}

static int	e_infnan(double n, int fl[8], char *s)
{
	int		ret;

	ret = 0;
	if (n != n || (n == 1.0 / 0.0) || (n == -1.0 / 0.0))
	{
		fl[1] = 0;
		ret += e_preformat(n, fl, 0);
		if (n != n)
			ret += (ft_islower(*(s + mp(s)))) ? ft_putstr("nan")
				: ft_putstr("NAN");
		else if (n == 1.0 / 0.0 || n == -1.0 / 0.0)
			ret += (ft_islower(*(s + mp(s)))) ? ft_putstr("inf")
				: ft_putstr("INF");
		ret += e_postformat(n, fl, 0);
	}
	return (ret);
}

int			ft_pute(double n, int fl[8], char *s)
{
	double		i;
	double		f;
	int			ret;
	int			power;

	if ((ret = e_infnan(n, fl, s)))
		return (ret);
	fl[1] = (fl[1] == -1) ? 6 : fl[1];
	f = ft_rint(ft_modf(n / ft_pb(ft_gp(n), 10), &i) * ft_pb(fl[1], 10));
	(f < 0) ? f *= -1 : 0;
	(i < 0) ? i *= -1 : 0;
	power = ft_sci(&i, &f, ft_gp(n), fl);
	ret += e_preformat(n, fl, ft_numlen2(power) - 2) + ft_putchar((int)i + '0');
	ret += (fl[1] || fl[2]) ? ft_putchar('.') : 0;
	ret += g_loop(f, fl, s);
	ret += (ft_islower(*(s + mp(s)))) ? ft_putchar('e') : ft_putchar('E');
	ret += (power < 0) ? ft_putchar('-') : ft_putchar('+');
	ret += (ft_numlen2(power) == 1) ? ft_putdec(0, g_fl, "j") : 0;
	ret += ft_putdec((power) < 0 ? -power : power, g_fl, "j");
	ret += e_postformat(n, fl, ft_numlen2(power) - 2);
	return (ret);
}
