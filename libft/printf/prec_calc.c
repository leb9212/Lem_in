/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prec_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:27:18 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:38 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		prec_calc(int len, int fl[8], int str)
{
	int	index;

	if (len < fl[1])
	{
		index = -1;
		while (++index < fl[1] - len)
			(str) ? ft_putchar(' ') : ft_putchar('0');
		return (fl[1] - len);
	}
	return (0);
}
