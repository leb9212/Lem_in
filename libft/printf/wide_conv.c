/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wide_conv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:43:19 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:44:09 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*wtos(wchar_t c, char b[5])
{
	ft_bzero(b, 5);
	if (c < (1 << 7))
		b[0] = (char)(c);
	else if (c < (1 << 11))
	{
		b[0] = (char)((c >> 6) | 0xC0);
		b[1] = (char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 16))
	{
		b[0] = (char)((c >> 12) | 0xE0);
		b[1] = (char)(((c >> 6) & 0x3F) | 0x80);
		b[2] = (char)((c & 0x3F) | 0x80);
	}
	else if (c < (1 << 21))
	{
		b[0] = (char)((c >> 18) | 0xF0);
		b[1] = (char)(((c >> 12) & 0x3F) | 0x80);
		b[2] = (char)(((c >> 6) & 0x3F) | 0x80);
		b[3] = (char)((c & 0x3F) | 0x80);
	}
	return (b);
}

int		ft_wlen(wchar_t *s, int fl[8])
{
	int		index;
	int		len;
	char	temp[5];

	len = 0;
	index = 0;
	if (s)
	{
		if (fl[1] == -1)
			while (s[index])
				len += ft_strlen(wtos(s[index++], temp));
		else
			while (s[index] && (len + (int)ft_strlen(wtos(s[index], temp)))
					<= fl[1])
				len += ft_strlen(wtos(s[index++], temp));
	}
	return (len);
}
