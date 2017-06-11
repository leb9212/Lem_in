/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/29 19:36:21 by exam              #+#    #+#             */
/*   Updated: 2016/11/25 16:57:33 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_change_to_num(char c, int str_base)
{
	if (c >= '0' && c <= '9')
		return ((c - '0' < str_base) ? (c - '0') : -1);
	else if (c >= 'a' && c <= 'f')
		return (((c - 'a') < (str_base - 10)) ? (c - 'a' + 10) : -1);
	else if (c >= 'A' && c <= 'F')
		return (((c - 'A') < (str_base - 10)) ? (c - 'A' + 10) : -1);
	return (-1);
}

int			ft_atoi_base(const char *str, int str_base)
{
	int index;
	int	sign;
	int num;

	sign = 1;
	index = 0;
	num = 0;
	if (str_base < 2 || str_base > 16)
		return (0);
	while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
		index++;
	if (str[index] == '+' || str[index] == '-')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] != '\0' && ft_change_to_num(str[index], str_base) != -1)
	{
		num = str_base * num + ft_change_to_num(str[index], str_base);
		index++;
	}
	return (sign * num);
}
