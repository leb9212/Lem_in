/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mfw_prec_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 21:09:28 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:26 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pos_parser(char *str, va_list *args, va_list copy)
{
	int		dollar;
	int		index;

	if (ft_isdigit(*str))
	{
		dollar = ft_atoi(str);
		str += ft_numlen(dollar);
		if (*str == '$')
		{
			index = 0;
			va_copy(*args, copy);
			while (++index < dollar)
				va_arg(*args, void *);
			return (ft_numlen(dollar) + 1);
		}
	}
	return (0);
}

int		mfw_parser(char *str, int fl[8], va_list *args)
{
	int		len;

	fl[0] = 0;
	len = 0;
	while (*str == '*' || ft_isdigit(*str))
	{
		if (*str == '*')
		{
			fl[0] = va_arg(*args, int);
			if (fl[0] < 0)
			{
				fl[0] = -fl[0];
				fl[4] = 1;
			}
			str += 1;
			len += 1;
		}
		else if (ft_isdigit(*str))
		{
			fl[0] = ft_atoi(str);
			str += ft_numlen(fl[0]);
			len += ft_numlen(fl[0]);
		}
	}
	return (len);
}

int		prec_parser(char *str, int fl[8], va_list *args)
{
	int		len;

	fl[1] = -1;
	len = 0;
	if (*str == '.' && (ft_isdigit(*(str + 1)) || *(str + 1) == '*'))
	{
		if (*(str + 1) == '*')
		{
			fl[1] = va_arg(*args, int);
			(fl[1] < 0) ? fl[1] = -1 : 0;
			str += 2;
			len += 2;
		}
		else if (ft_isdigit(*(str + 1)))
		{
			fl[1] = ft_atoi(str + 1);
			str += ft_numlen(fl[1]) + 1;
			len += ft_numlen(fl[1]) + 1;
		}
	}
	else if (*str++ == '.' && !(fl[1] = 0))
		len += 1;
	return (len);
}
