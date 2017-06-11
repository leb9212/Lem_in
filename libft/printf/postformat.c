/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   postformat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:20:48 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:34 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_postformat(int fl[8], int len, intmax_t n)
{
	int		index;
	int		ret;

	ret = 0;
	if (fl[4] && MAX(len, fl[1]) < fl[0])
	{
		index = ((!fl[2] || (len <= fl[1]))
				&& (n < 0 || fl[5] || fl[6])) ? 0 : -1;
		while (++index < fl[0] - MAX(len, fl[1]))
		{
			ft_putchar(' ');
			ret++;
		}
		return (ret);
	}
	return (0);
}

int		ft_postformat2(int fl[8], int len)
{
	int		index;
	int		ret;

	ret = 0;
	if (fl[4] && len < fl[0])
	{
		index = (fl[2] || !fl[5]) ? -1 : 0;
		while (++index < fl[0] - len)
		{
			ft_putchar(' ');
			ret++;
		}
		return (ret);
	}
	return (0);
}

int		ft_postformat3(int fl[8], int len)
{
	int		index;
	int		ret;

	ret = 0;
	if (fl[4] && MAX(len, fl[1]) < fl[0])
	{
		index = -1;
		while (++index < fl[0] - MAX(len, fl[1]))
		{
			ft_putchar(' ');
			ret++;
		}
		return (ret);
	}
	return (0);
}
