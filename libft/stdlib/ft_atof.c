/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/24 16:44:27 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 19:18:59 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_isinf(const char *s)
{
	int		index;

	index = 0;
	while (ft_isspace(s[index]))
		index++;
	if (ft_strnequ(ft_strlowcase((char*)&s[index]), "inf", 3))
		return (1);
	else if (ft_strnequ(ft_strlowcase((char*)&s[index]), "-inf", 4))
		return (-1);
	else
		return (0);
}

static int		ft_isnan(const char *s)
{
	int		index;

	index = 0;
	while (ft_isspace(s[index]))
		index++;
	if (ft_strnequ(ft_strlowcase((char*)&s[index]), "nan", 3))
		return (1);
	else
		return (0);
}

static float	ft_inf(int p)
{
	int		inf;

	inf = 0x7F800000;
	return (p * *(float*)&inf);
}

static float	ft_nan(void)
{
	int		nan;

	nan = 0x7F800001;
	return (*(float*)&nan);
}

double			ft_atof(const char *s)
{
	long double	result;
	int			sign;
	int			dot;
	int			e;

	result = 0;
	if (s == NULL)
		return (0);
	if (ft_isinf(s))
		return (ft_inf(ft_isinf(s)));
	if (ft_isnan(s))
		return (ft_nan());
	while (ft_isspace(*s))
		s++;
	sign = (*s == '-' && ft_isdigit(*(s + 1))) ? -1 : 1;
	sign = (*s == '-' && *(s + 1) == '.' && ft_isdigit(*(s + 2))) ? -1 : sign;
	s = (*s == '+' || *s == '-') ? (s + 1) : s;
	while (ft_isdigit(*s))
		result = result * 10 + (long double)(*s++ - '0');
	if (*s == '.' && (dot = 1))
		while (ft_isdigit(*(++s)))
			result += (long double)(*s - '0') / ft_pb(dot++, 10);
	e = (*s == 'e' && !ft_isspace(*(s + 1))) ? ft_atoi(s + 1) : 0;
	return (result * sign * ft_pb(e, 10));
}
