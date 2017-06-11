/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mod_spec_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 18:29:24 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:30 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_mod(char c)
{
	if (c == 'h' || c == 'l' || c == 'j' || c == 'z' || c == 'L')
		return (1);
	else
		return (0);
}

int		is_spec(char c)
{
	if (c == 'd' || c == 'i' || c == 'D' || c == 'p' || c == 'n' || c == '%' ||
		c == 'u' || c == 'U' || c == 'o' || c == 'O' || c == 'x' || c == 'X' ||
		c == 'f' || c == 'F' || c == 'e' || c == 'E' || c == 'g' || c == 'G' ||
		c == 'a' || c == 'A' || c == 'c' || c == 'C' || c == 's' || c == 'S' ||
		c == 'b' || c == 'v' || c == 'r')
		return (1);
	else
		return (0);
}

int		mp(char *str)
{
	int		len;

	len = 0;
	while (is_mod(str[len]) && str[len])
		len++;
	return (len);
}

char	sp(char *s)
{
	while (is_mod(*s) && *s)
		s++;
	return (*s);
}
