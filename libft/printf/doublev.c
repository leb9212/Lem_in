/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doublev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:21:55 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:41:59 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int	g_fl[8];

static char	*ft_itoa_bin(double flo, int p)
{
	int					len;
	char				*bin;
	unsigned long long	n;

	n = *((unsigned long long *)&flo) & 0x000FFFFFFFFFFFFFULL;
	len = 52;
	bin = (char*)malloc(sizeof(char) * (len + 1));
	bin[len] = '\0';
	while (len-- > 0)
	{
		bin[len] = n % 2 + '0';
		n /= 2;
	}
	if ((len = 52) && p != -1 && p < 52 && bin[p] > '0')
	{
		bin[p - 1]++;
		while (--p > 0 && bin[p] == '2')
		{
			bin[p] = '0';
			bin[p - 1]++;
		}
	}
	while (--len >= 0 && bin[len] == '0')
		bin[len] = '\0';
	return (bin);
}

static int	v_preformat(double n, int fl[8], int len)
{
	int		index;
	int		ret;

	ret = 0;
	ret += (fl[3] && is_neg(n) && !is_in(n)) ? ft_putchar('-') : 0;
	ret += (fl[3] && fl[5] && !is_neg(n) && !is_in(n))
		? ft_putchar('+') : 0;
	ret += (fl[3] && fl[6] && !fl[5] && !is_neg(n) && !is_in(n))
		? ft_putchar(' ') : 0;
	ret += (fl[3] && !is_in(n)) ? ft_putstr("0b") : 0;
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
	ret += (!fl[3] && !is_in(n)) ? ft_putstr("0b") : 0;
	return (ret);
}

static int	v_postformat(double n, int fl[8], int len)
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

static int	v_infnanzero(double n, int fl[8])
{
	int		ret;
	int		index;

	ret = 0;
	if (is_zero(n) && (fl[1] = (fl[1] < 0) ? 0 : fl[1]) >= 0)
	{
		ret += v_preformat(n, fl, 6 + fl[1]);
		ret += ft_putchar('0');
		ret += (fl[1] || fl[2]) ? ft_putchar('.') : 0;
		index = -1;
		while (++index < fl[1])
			ret += ft_putchar('0');
		ret += ft_putstr("p+0");
		ret += v_postformat(n, fl, 6 + fl[1]);
	}
	if ((n != n || (n == 1.0 / 0.0) || (n == -1.0 / 0.0)) && !(fl[1] = 0))
	{
		ret += v_preformat(n, fl, 3);
		if (n != n)
			ret += ft_putstr("nan");
		else if (n == 1.0 / 0.0 || n == -1.0 / 0.0)
			ret += ft_putstr("inf");
		ret += v_postformat(n, fl, 3);
	}
	return (ret);
}

int			ft_putv(double n, int fl[8], char *s)
{
	int		index;
	int		ret;
	char	*bin;

	(void)s;
	if ((ret = v_infnanzero(n, fl)))
		return (ret);
	bin = ft_itoa_bin(n, fl[1]);
	fl[1] = (fl[1] == -1) ? ft_strlen(bin) : fl[1];
	ret += v_preformat(n, fl, fl[1] + 5 + ft_numlen2(get_exponent(n)));
	ret += ((bin[0] > '0' && !fl[1]) || bin[0] == '2')
		? ft_putchar('2') : ft_putchar('1');
	bin[0] = (bin[0] == '2') ? '0' : bin[0];
	ret += ((fl[1]) || fl[2]) ? ft_putchar('.') : 0;
	index = 0;
	while (index < fl[1] && bin[index])
		ret += ft_putchar(bin[index++]);
	while (index++ < fl[1])
		ret += ft_putchar('0');
	ret += ft_putchar('p');
	ret += (get_exponent(n) >= 0) ? ft_putchar('+') : 0;
	ret += ft_putdec(get_exponent(n), g_fl, "d");
	ret += v_postformat(n, fl, fl[1] + 5 + ft_numlen2(get_exponent(n)));
	free(bin);
	return (ret);
}
