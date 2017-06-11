/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 21:09:41 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:12 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isflag(char c)
{
	if (c == '#' || c == '0' || c == '-' || c == '+' || c == ' ' || c == '\'')
		return (1);
	return (0);
}

int		flag_parser(char *str, int fl[8])
{
	int		index;
	int		len;

	index = 1;
	while (++index < 8)
		fl[index] = 0;
	len = 0;
	while (*str && ft_isflag(*str))
	{
		if (*str == '#')
			fl[2] = 1;
		else if (*str == '0')
			fl[3] = 1;
		else if (*str == '-')
			fl[4] = 1;
		else if (*str == '+')
			fl[5] = 1;
		else if (*str == ' ')
			fl[6] = 1;
		else if (*str == '\'')
			fl[7] = 1;
		str++;
		len++;
	}
	return (len);
}
