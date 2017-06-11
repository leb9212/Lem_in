/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrimc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 00:22:18 by elee              #+#    #+#             */
/*   Updated: 2016/09/26 00:24:07 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_trim(char c, char trim)
{
	if (c == trim)
		return (1);
	else
		return (0);
}

static int	all_trim(char const *s, char trim)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (is_trim(s[index], trim) == 0)
			return (0);
		index++;
	}
	return (1);
}

char		*ft_strtrimc(char const *s, char trim)
{
	int		start_index;
	int		stop_index;
	int		copy_index;
	char	*trimed;

	if (s == NULL)
		return (NULL);
	if (all_trim(s, trim))
	{
		trimed = ft_strnew(0);
		return (trimed);
	}
	start_index = 0;
	stop_index = ft_strlen(s) - 1;
	while (is_trim(s[start_index], trim))
		start_index++;
	while (is_trim(s[stop_index], trim))
		stop_index--;
	trimed = ft_strnew(stop_index - start_index + 1);
	if (trimed == NULL)
		return (NULL);
	copy_index = -1;
	while (start_index + ++copy_index <= stop_index)
		trimed[copy_index] = s[start_index + copy_index];
	return (trimed);
}
