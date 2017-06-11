/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:33:09 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:43:54 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

extern int g_fl[8];

static int	ft_str_zerocase(void *str, int fl[8])
{
	int		index;
	int		ret;
	int		nuls;
	char	*s;

	ret = 0;
	s = "(null)";
	if (!str)
	{
		nuls = (fl[1] == -1) ? 6 : MIN(fl[1], 6);
		index = -1;
		while (!fl[4] && ++index < fl[0] - nuls)
			ret += (fl[3]) ? ft_putchar('0') : ft_putchar(' ');
		index = -1;
		if (fl[1] == -1)
			ret += ft_putstr(s);
		else
			while (++index < fl[1] && *s)
				ret += ft_putchar(*(s++));
		index = -1;
		while (fl[4] && ++index < (fl[0] - nuls))
			ret += ft_putchar(' ');
		return (ret);
	}
	return (-1);
}

int			ft_puts(char *s, int fl[8])
{
	int		index;
	int		len;
	int		ret;

	if ((ret = ft_str_zerocase(s, fl)) > -1)
		return (ret);
	ret++;
	len = (fl[1] == 0) ? 0 : ft_strlen(s);
	len = (fl[1] < 0) ? ft_strlen(s) :
							MIN((int)ft_strlen(s), fl[1]);
	ret += ft_preformat3(fl, len, (void*)s);
	ret += (len && fl[1] == -1) ? ft_putstr(s) : 0;
	if (len && fl[1] != -1)
	{
		index = 0;
		while (s[index] && index < fl[1] && ++ret)
			ft_putchar(s[index++]);
	}
	ret += ft_postformat2(fl, len - (fl[5] && !fl[2]));
	return (ret);
}

int			ft_putr(char *s, int fl[8])
{
	int		index;
	int		len;
	int		ret;

	if ((ret = ft_str_zerocase(s, fl)) > -1)
		return (ret);
	ret++;
	len = (fl[1] == 0) ? 0 : ft_strlen(s);
	len = (fl[1] < 0) ? ft_strlen(s) :
							MIN((int)ft_strlen(s), fl[1]);
	ret += ft_preformat3(fl, len, (void*)s);
	ret += (len && fl[1] == -1) ? ft_putstr(s) : 0;
	if (len && fl[1] != -1)
	{
		index = 0;
		while (s[index] && index < fl[1] && ++ret)
		{
			if (s[index] >= 32 && s[index] <= 126)
				ft_putchar(s[index++]);
			else
				ft_putchar('.');
		}
	}
	ret += ft_postformat2(fl, len - (fl[5] && !fl[2]));
	return (ret);
}

static int	ft_capserror(wchar_t *s)
{
	int		i;

	i = -1;
	while (s[++i])
		if (s[i] < 0 || (s[i] > 55295 && s[i] < 57344) || s[i] > 1114111)
			return (0);
	return (1);
}

int			ft_putcaps(wchar_t *s, int fl[8])
{
	int		index;
	char	temp[5];
	int		len;
	int		count;
	int		ret;

	if ((ret = ft_str_zerocase(s, fl)) > -1)
		return (ret);
	if (!(count = 0) && !ft_capserror(s))
		return (-1);
	ret++;
	len = (fl[1] == 0) ? 0 : ft_wlen(s, fl);
	ret += ft_preformat3(fl, len, (void*)s);
	index = -1;
	ret += (fl[0] && fl[1] > len && fl[4]) ? prec_calc(len, fl, 1) : 0;
	while (len && s[++index] && count < len)
	{
		if (ft_strlen(wtos(s[index], temp)) > 1)
			ft_putcapc(s[index], g_fl);
		else
			ft_putc(s[index], g_fl);
		count += ft_strlen(wtos(s[index], temp));
	}
	ret += ft_postformat(fl, len, 0);
	return (ret + count);
}
