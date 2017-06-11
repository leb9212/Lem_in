/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 21:55:04 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:07 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_plen(void *input)
{
	char		*hex;
	uintptr_t	ptr;
	int			index;
	int			len;

	if (input == NULL)
		return (1);
	len = 0;
	hex = "0123456789abcdef";
	ptr = (uintptr_t)input;
	index = 60;
	while (hex[(ptr >> index) & 0xf] == '0' && index)
		index -= 4;
	len += (index / 4) + 1;
	return (len);
}

static int	ft_mem_zerocase(void *input, int fl[8])
{
	int		index;
	int		ret;

	ret = 0;
	if (fl[1] == 0 && input == NULL)
	{
		index = -1;
		while (!fl[4] && ++index < fl[0] - 2)
			ret += ft_putchar(' ');
		ret += ft_putstr("0x");
		while (fl[4] && ++index < fl[0] - 2)
			ret += ft_putchar(' ');
		return (ret);
	}
	return (-1);
}

int			ft_putp(void *input, int fl[8])
{
	char		*hex;
	uintptr_t	ptr;
	int			index;
	int			len;
	int			ret;

	if ((ret = ft_mem_zerocase(input, fl)) > -1)
		return (ret);
	ret++;
	len = ft_plen(input);
	hex = "0123456789abcdef";
	ptr = (uintptr_t)input;
	ret += (fl[1] == -1 && fl[3]) ? ft_putstr("0x") : 0;
	ret += ft_preformat4(fl, MAX(len + 2, fl[1]
				+ (input != NULL) * 2) + (fl[1] != -1 && input == NULL) * 2);
	ret += (!fl[3] || fl[1] != -1) ? ft_putstr("0x") : 0;
	ret += prec_calc(len, fl, 0);
	ret += (input == NULL) ? ft_putchar('0') : 0;
	index = len * 4;
	while (input && (index -= 4) >= 0 && ++ret)
		ft_putchar(hex[(ptr >> index) & 0xf]);
	ret += ft_postformat(fl, MAX(len + 2, fl[1]
				+ (input != NULL) * 2) + (fl[1] != -1 && input == NULL) * 2
			- (fl[5] && !fl[2]), 0);
	return (ret);
}

int			ft_putextra(char c, int fl[8])
{
	int		ret;

	if (c == '\0')
		return (0);
	ret = 0;
	ret += ft_preformat(fl, 1);
	ret += ft_putchar(c);
	ret += ft_postformat2(fl, 1 - (fl[5] && !fl[2]));
	return (ret);
}

int			ft_putn(int *n, int len)
{
	*n = len;
	return (0);
}
