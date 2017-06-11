/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/27 15:33:06 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:41:37 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putc(int c, int fl[8])
{
	int	ret;

	ret = 0;
	ret += ft_preformat(fl, 1);
	ret += ft_putchar(c);
	ret += ft_postformat2(fl, 1 - (fl[5] && !fl[2]));
	return (ret);
}

int		ft_putcapc(wchar_t c, int fl[8])
{
	int		len;
	int		ret;
	char	temp[5];

	if (c < 0 || (c > 55295 && c < 57344) || c > 1114111)
		return (-1);
	ret = 0;
	wtos(c, temp);
	len = ft_strlen(temp);
	len = (temp[0] == '\0') ? 1 : len;
	ret += ft_preformat(fl, len);
	ret += (temp[0] == '\0') ? ft_putchar('\0') : ft_putstr(temp);
	ret += ft_postformat2(fl, len - (fl[5] && !fl[2]));
	return (ret);
}
