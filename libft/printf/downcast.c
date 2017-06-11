/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   downcast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:20:28 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:04 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

intmax_t	dec_downcast(intmax_t n, char *str)
{
	if (!ft_strncmp(str, "d", 1) || !ft_strncmp(str, "i", 1))
		return ((int)n);
	else if (!ft_strncmp(str, "D", 1)
			|| !ft_strncmp(str + 1, "D", 1)
			|| !ft_strncmp(str + 2, "D", 1))
		return ((long)n);
	else if (!ft_strncmp(str, "hh", 2))
		return ((char)n);
	else if (!ft_strncmp(str, "h", 1))
		return ((short)n);
	else if (!ft_strncmp(str, "l", 1))
		return ((long)n);
	else if (!ft_strncmp(str, "ll", 2))
		return ((long long)n);
	return (n);
}

size_t		uns_downcast(size_t n, char *str)
{
	if (!ft_strncmp(str, "o", 1) || !ft_strncmp(str, "u", 1)
		|| !ft_strncmp(str, "x", 1) || !ft_strncmp(str, "X", 1))
		return ((unsigned int)n);
	else if (!ft_strncmp(str, "O", 1) || !ft_strncmp(str, "U", 1)
			|| !ft_strncmp(str + 1, "O", 1) || !ft_strncmp(str + 1, "U", 1)
			|| !ft_strncmp(str + 2, "O", 1) || !ft_strncmp(str + 2, "U", 1))
		return ((unsigned long)n);
	else if (!ft_strncmp(str, "hh", 2))
		return ((unsigned char)n);
	else if (!ft_strncmp(str, "h", 1))
		return ((unsigned short)n);
	else if (!ft_strncmp(str, "l", 1))
		return ((unsigned long)n);
	else if (!ft_strncmp(str, "ll", 2))
		return ((unsigned long long)n);
	else if (!ft_strncmp(str, "j", 2))
		return ((uintmax_t)n);
	return (n);
}
