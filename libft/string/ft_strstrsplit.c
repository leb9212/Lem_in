/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstrsplit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/27 22:51:28 by elee              #+#    #+#             */
/*   Updated: 2016/09/30 18:20:02 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_delim(char const *str, char *delim)
{
	int	length;
	int	index;
	int	count;

	index = 0;
	count = 0;
	length = ft_strlen(delim);
	if (length == 0)
		return (0);
	while (index < length && *(str + index) != '\0')
	{
		if (*(str + index) == *(delim + index))
			count++;
		index++;
	}
	if (count == length)
		return (1);
	else
		return (0);
}

static int	wc(char const *str, char *delim)
{
	int		index;
	int		count;
	int		length;

	index = 0;
	count = 0;
	length = ft_strlen(delim);
	if (length == 0)
		return (1);
	while (str[index])
	{
		while (is_delim(&str[index], delim))
			index += length;
		if (!is_delim(&str[index], delim) && str[index] != '\0')
			count++;
		while (!is_delim(&str[index], delim) && str[index] != '\0')
			index++;
	}
	return (count);
}

static int	w_size(char const *str, int index, char *delim)
{
	int		size;

	size = 0;
	while (is_delim(&str[index], delim) == 0 && str[index] != '\0')
	{
		index++;
		size++;
	}
	return (size);
}

static void	free_loop(char **w, int stop_index)
{
	int		index;

	index = 0;
	while (index < stop_index)
	{
		free(w[index]);
		index++;
	}
	free(w);
	w = NULL;
}

char		**ft_strstrsplit(char const *s, char *c)
{
	char	**w;
	int		i;
	int		j;
	int		k;

	if (!s || !c || (w = (char**)malloc(sizeof(char*) * (wc(s, c) + 1))) == 0)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < wc(s, c))
	{
		while (is_delim(&s[j], c))
			j += ft_strlen(c);
		if ((w[i] = (char*)malloc(sizeof(char) * (w_size(s, j, c) + 1))) == 0)
		{
			free_loop(w, i);
			return (NULL);
		}
		k = 0;
		while (!is_delim(&s[j], c) && s[j] != '\0')
			w[i][k++] = s[j++];
		w[i][k] = '\0';
	}
	w[wc(s, c)] = NULL;
	return (w);
}
