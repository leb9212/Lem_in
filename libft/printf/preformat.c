/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preformat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:21:33 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:41 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_preformat(int fl[8], int len)
{
	int		index;

	if (!fl[4] && fl[0] > len)
	{
		index = -1;
		while (++index < fl[0] - len)
			(fl[3]) ? ft_putchar('0') : ft_putchar(' ');
		return (fl[0] - len);
	}
	return (0);
}

int		ft_preformat2(int fl[8], int len, intmax_t n)
{
	int		index;
	int		ret;

	ret = 0;
	if (!fl[4] && MAX(len, fl[1]) < fl[0])
	{
		index = (n < 0 || fl[5] || fl[6]) ? 0 : -1;
		while (++index < fl[0] - MAX(len, fl[1]))
		{
			(fl[3] && fl[1] == -1) ? ft_putchar('0') : ft_putchar(' ');
			ret++;
		}
		return (ret);
	}
	return (0);
}

int		ft_preformat3(int fl[8], int len, void *s)
{
	int		index;
	int		ret;

	ret = 0;
	if ((!fl[4] && fl[3] && fl[0] > len)
		|| (!fl[3] && !fl[4] && s))
	{
		index = -1;
		while (++index < fl[0] - len)
		{
			(fl[3]) ? ft_putchar('0') : ft_putchar(' ');
			ret++;
		}
		return (ret);
	}
	return (0);
}

int		ft_preformat4(int fl[8], int len)
{
	int		index;

	if (!fl[4] && fl[0] > len)
	{
		index = -1;
		while (++index < fl[0] - len)
			(fl[3] && fl[1] == -1) ? ft_putchar('0') : ft_putchar(' ');
		return (fl[0] - len);
	}
	return (0);
}

int		ft_preformat5(int fl[8], int len)
{
	int		index;
	int		ret;

	ret = 0;
	if (!fl[4] && MAX(len, fl[1]) < fl[0])
	{
		index = -1;
		while (++index < fl[0] - MAX(len, fl[1]))
		{
			(fl[3] && fl[1] == -1) ? ft_putchar('0') : ft_putchar(' ');
			ret++;
		}
		return (ret);
	}
	return (0);
}
