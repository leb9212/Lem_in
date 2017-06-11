/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:09:03 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:41:40 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(intmax_t n, int fl[8])
{
	if (n < 0)
		return (1);
	else if (fl[5] && n >= 0)
		return (1);
	else if (fl[6] && n >= 0)
		return (1);
	return (0);
}

static int	ft_sign(intmax_t n, int fl[8])
{
	int		ret;

	ret = 0;
	if (n < 0)
		ret += ft_putchar('-');
	else if (fl[5] && n >= 0)
		ret += ft_putchar('+');
	else if (fl[6] && n >= 0)
		ret += ft_putchar(' ');
	return (ret);
}

static int	ft_dec_zerocase(intmax_t n, int fl[8])
{
	int		index;
	int		ret;
	int		nuls;

	ret = 0;
	if ((!fl[1]) && !n)
	{
		index = -1;
		nuls = ft_issign(n, fl);
		ret += nuls;
		(fl[4]) ? ft_sign(n, fl) : 0;
		while (!(fl[4]) && (fl[3]) && ++index < fl[0] - nuls)
			ret += ft_putchar(' ');
		while ((!fl[3]) && ++index < fl[0] - nuls)
			ret += ft_putchar(' ');
		(!fl[4]) ? ft_sign(n, fl) : 0;
		while ((fl[4]) && (fl[3]) && ++index < fl[0] - nuls)
			ret += ft_putchar(' ');
		return (ret);
	}
	return (-1);
}

int			ft_putdec(intmax_t ptr, int fl[8], char *str)
{
	int			len;
	intmax_t	n;
	int			ret;
	int			sign;

	n = dec_downcast(ptr, str);
	if ((ret = ft_dec_zerocase(n, fl)) > -1)
		return (ret);
	ret++;
	len = ft_numlen2(n);
	len += (fl[7]) ? ((len - 1) / 3) : 0;
	sign = (fl[3] && fl[1] == -1) ? ft_sign(n, fl) : 0;
	ret += len;
	ret += ft_preformat2(fl, len +
			(sign && n == 0 && fl[1] != -1), n);
	sign += (!fl[3] || fl[1] != -1) ? ft_sign(n, fl) : 0;
	ret += sign;
	ret += prec_calc(len, fl, 0);
	ft_putdi(n, fl);
	ret += ft_postformat(fl, len +
			((sign && n == 0 && fl[1] != -1)
			|| (fl[2] && fl[3])), n);
	return (ret);
}
