/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uns.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:43:14 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:52 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_uns_zerocase(size_t n, char spec, int fl[8])
{
	int	i;
	int	ret;
	int	nuls;

	if ((fl[3] || !fl[1]) && !n && !(ret = 0))
	{
		i = -1;
		while (!fl[4] && ++i < fl[0] - fl[1] - (fl[1] == -1))
			ret += (fl[3] && fl[1] == -1) ? ft_putchar('0') : ft_putchar(' ');
		i = -1;
		while (++i < fl[1])
			ret += ft_putchar('0');
		if (spec == 'o' && fl[2] && fl[1] == 0)
			ret += ft_putchar('0');
		nuls = (ret == 0 && fl[1] == -1) ? ft_putchar('0') : 0;
		if ((i = -1) && fl[1] != -1)
			while (fl[4] && ++i < fl[0] - fl[1] -
				((spec == 'o' || spec == 'b') && fl[2] && fl[1] == 0))
				ret += ft_putchar(' ');
		else if (fl[1] == -1 && (ret += nuls) >= 0)
			while (fl[4] && ++i < fl[0] - nuls)
				ret += ft_putchar(' ');
		return (ret);
	}
	return (-1);
}

int			ft_putuns(size_t i, int fl[8], char *str)
{
	int		len;
	size_t	n;
	int		ret;

	n = uns_downcast(i, str);
	if ((ret = ft_uns_zerocase(n, 'u', fl)) > -1)
		return (ret);
	ret++;
	len = ft_unsignedlen(n, 10);
	len += (fl[7]) ? ((len - 1) / 3) : 0;
	ret += len;
	ret += ft_preformat5(fl, len);
	ret += prec_calc(len, fl, 0);
	ft_putu(n, fl);
	ret += ft_postformat3(fl, len);
	return (ret);
}

int			ft_putbin(size_t i, int fl[8], char *str)
{
	int		len;
	size_t	n;
	int		ret;

	n = uns_downcast(i, str);
	if ((ret = ft_uns_zerocase(n, 'b', fl)) > -1)
		return (ret);
	ret++;
	len = ft_unsignedlen(n, 2);
	ret += len;
	(fl[2] && n != 0) ? len++ : 0;
	ret += (fl[2] && fl[3] && n) ? ft_putchar('0') : 0;
	ret += ft_preformat5(fl, len);
	ret += (fl[2] && !fl[3] && n) ? ft_putchar('0') : 0;
	ret += prec_calc(len, fl, 0);
	ft_putb(n);
	ret += ft_postformat3(fl, len);
	return (ret);
}

int			ft_putoct(size_t i, int fl[8], char *str)
{
	int		len;
	size_t	n;
	int		ret;

	n = uns_downcast(i, str);
	if ((ret = ft_uns_zerocase(n, 'o', fl)) > -1)
		return (ret);
	ret++;
	len = ft_unsignedlen(n, 8);
	ret += len;
	(fl[2] && n != 0) ? len++ : 0;
	ret += (fl[2] && fl[3] && n) ? ft_putchar('0') : 0;
	ret += ft_preformat5(fl, len);
	ret += (fl[2] && !fl[3] && n) ? ft_putchar('0') : 0;
	ret += prec_calc(len, fl, 0);
	ft_puto(n);
	ret += ft_postformat3(fl, len);
	return (ret);
}

int			ft_puthex(size_t i, int fl[8], char *str)
{
	int		len;
	size_t	n;
	int		ret;
	int		a;
	char	spec;

	n = uns_downcast(i, str);
	spec = *(str + mp(str));
	if ((ret = ft_uns_zerocase(n, 'x', fl)) > -1)
		return (ret);
	ret++;
	len = ft_unsignedlen(n, 16);
	ret += len;
	(fl[2] && fl[1] == -1 && n) ? len += 2 : 0;
	ret += (fl[2] && fl[3] && n && spec == 'x') ? ft_putstr("0x") : 0;
	ret += (fl[2] && fl[3] && n && spec == 'X') ? ft_putstr("0X") : 0;
	ret += ft_preformat5(fl, len);
	ret += (fl[2] && !fl[3] && n && spec == 'x') ? ft_putstr("0x") : 0;
	ret += (fl[2] && !fl[3] && n && spec == 'X') ? ft_putstr("0X") : 0;
	a = prec_calc(len, fl, 0);
	len += a;
	ret += a;
	ft_putx(n, spec);
	ret += ft_postformat3(fl, len + (fl[2] && fl[1] != -1) * 2);
	return (ret);
}
