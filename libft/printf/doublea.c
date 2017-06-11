/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublea.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:41:51 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:41:45 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int	g_fl[8];

static char	*ft_itoa_hex(double flo, int p, char spec)
{
	int					len;
	char				*hex;
	unsigned long long	n;

	n = *((unsigned long long *)&flo) & 0x000FFFFFFFFFFFFFULL;
	len = 13;
	hex = (char*)malloc(sizeof(char) * (len + 1));
	hex[len] = '\0';
	while (len-- > 0)
	{
		hex[len] = ((n % 16) > 9) ? (spec + (n % 16) - 10) : ((n % 16) + '0');
		n /= 16;
	}
	if ((len = 13) && p != -1 && p < 13 && hex[p] > '7')
	{
		hex[p - 1] = (hex[p - 1] != '9') ? (hex[p - 1] + 1) : spec;
		while (--p > 0 && (hex[p] == 'g' || hex[p] == 'G'))
		{
			hex[p] = '0';
			hex[p - 1] = (hex[p - 1] != '9') ? (hex[p - 1] + 1) : spec;
		}
	}
	while (--len >= 0 && hex[len] == '0')
		hex[len] = '\0';
	return (hex);
}

static int	a_preformat(double n, int fl[8], int len, char c)
{
	int		index;
	int		ret;

	ret = 0;
	ret += (fl[3] && is_neg(n) && !is_in(n)) ? ft_putchar('-') : 0;
	ret += (fl[3] && fl[5] && !is_neg(n) && !is_in(n))
		? ft_putchar('+') : 0;
	ret += (fl[3] && fl[6] && !fl[5] && !is_neg(n) && !is_in(n))
		? ft_putchar(' ') : 0;
	ret += (fl[3] && !is_in(n)) ? (ft_putchar('0') + ft_putchar(c + 23)) : 0;
	if (!fl[4] && len + (fl[1] > 0) < fl[0])
	{
		index = ((n != n && is_neg(n)) || fl[5] || fl[6]) ? 0 : -1;
		index += (fl[2] && !fl[1] && !is_in(n)) ? 1 : 0;
		while (++index < fl[0] - len - (fl[1] > 0))
			ret += (!is_in(n) && fl[3]) ? ft_putchar('0') : ft_putchar(' ');
	}
	ret += (is_neg(n) && n == n &&
			(!fl[3] || is_in(n))) ? ft_putchar('-') : 0;
	ret += (!is_neg(n) && n == n && fl[5] &&
			(!fl[3] || is_in(n))) ? ft_putchar('+') : 0;
	ret += (!is_neg(n) && n == n && fl[6] && !fl[5] &&
			(!fl[3] || is_in(n))) ? ft_putchar(' ') : 0;
	ret += (!fl[3] && !is_in(n)) ? (ft_putchar('0') + ft_putchar(c + 23)) : 0;
	return (ret);
}

static int	a_postformat(double n, int fl[8], int len)
{
	int		index;
	int		ret;

	ret = 0;
	if (fl[4] && len + (fl[1] > 0) < fl[0])
	{
		index = ((n != n && is_neg(n)) || fl[5] || fl[6]) ? 0 : -1;
		index += (fl[2] && !fl[1] && !is_in(n)) ? 1 : 0;
		while (++index < fl[0] - len - (fl[1] > 0))
			ret += ft_putchar(' ');
		return (ret);
	}
	return (0);
}

static int	a_infnanzero(double n, int fl[8], char spec)
{
	int		ret;
	int		index;

	ret = 0;
	if (is_zero(n) && (fl[1] = (fl[1] < 0) ? 0 : fl[1]) >= 0)
	{
		ret += a_preformat(n, fl, 6 + fl[1], spec);
		ret += ft_putchar('0');
		ret += (fl[1] || fl[2]) ? ft_putchar('.') : 0;
		index = -1;
		while (++index < fl[1])
			ret += ft_putchar('0');
		ret += (spec == 'A') ? ft_putstr("P+0") : ft_putstr("p+0");
		ret += a_postformat(n, fl, 6 + fl[1]);
	}
	if ((n != n || (n == 1.0 / 0.0) || (n == -1.0 / 0.0)) && !(fl[1] = 0))
	{
		ret += a_preformat(n, fl, 3, spec);
		if (n != n)
			ret += (spec == 'A') ? ft_putstr("NAN") : ft_putstr("nan");
		else if (n == 1.0 / 0.0 || n == -1.0 / 0.0)
			ret += (spec == 'A') ? ft_putstr("INF") : ft_putstr("inf");
		ret += a_postformat(n, fl, 3);
	}
	return (ret);
}

int			ft_puta(double n, int fl[8], char *s)
{
	int		index;
	int		ret;
	char	*hex;

	if ((ret = a_infnanzero(n, fl, *(s + mp(s)))))
		return (ret);
	hex = ft_itoa_hex(n, fl[1], *(s + mp(s)));
	fl[1] = (fl[1] == -1) ? ft_strlen(hex) : fl[1];
	ret += a_preformat(n, fl, fl[1] + 5 + ft_numlen2(get_exponent(n)),
			*(s + mp(s)));
	ret += (((hex[0] > '8' || (hex[0] > '7' && ft_tolower(hex[1]) > 'e')) &&
	!fl[1]) || ft_tolower(hex[0]) == 'g') ? ft_putchar('2') : ft_putchar('1');
	hex[0] = (hex[0] == 'g' || hex[0] == 'G') ? '0' : hex[0];
	ret += ((fl[1]) || fl[2]) ? ft_putchar('.') : 0;
	index = 0;
	while (index < fl[1] && hex[index])
		ret += ft_putchar(hex[index++]);
	while (index++ < fl[1])
		ret += ft_putchar('0');
	ret += (*(s + mp(s)) == 'A') ? ft_putchar('P') : ft_putchar('p');
	ret += (get_exponent(n) >= 0) ? ft_putchar('+') : 0;
	ret += ft_putdec(get_exponent(n), g_fl, "d");
	ret += a_postformat(n, fl, fl[1] + 5 + ft_numlen2(get_exponent(n)));
	free(hex);
	return (ret);
}
