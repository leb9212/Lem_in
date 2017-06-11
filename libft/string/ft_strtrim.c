/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 12:26:06 by elee              #+#    #+#             */
/*   Updated: 2016/09/24 16:07:43 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_whitespace(char c)
{
	if (c == ' ' || c == '\n' || c == '\t')
		return (1);
	else
		return (0);
}

static int	all_whitespace(char const *s)
{
	int		index;

	index = 0;
	while (s[index])
	{
		if (is_whitespace(s[index]) == 0)
			return (0);
		index++;
	}
	return (1);
}

char		*ft_strtrim(char const *s)
{
	int		start_index;
	int		stop_index;
	int		copy_index;
	char	*trim;

	if (s == NULL)
		return (NULL);
	if (all_whitespace(s))
	{
		trim = ft_strnew(0);
		return (trim);
	}
	start_index = 0;
	stop_index = ft_strlen(s) - 1;
	while (is_whitespace(s[start_index]))
		start_index++;
	while (is_whitespace(s[stop_index]))
		stop_index--;
	trim = ft_strnew(stop_index - start_index + 1);
	if (trim == NULL)
		return (NULL);
	copy_index = -1;
	while (start_index + ++copy_index <= stop_index)
		trim[copy_index] = s[start_index + copy_index];
	return (trim);
}
