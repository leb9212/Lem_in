/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 13:52:10 by elee              #+#    #+#             */
/*   Updated: 2016/09/26 17:17:22 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v')
		return (1);
	else
		return (0);
}

static int	word_count(char const *str)
{
	int		index;
	int		count;

	index = 0;
	count = 0;
	while (str[index])
	{
		while (is_sep(str[index]))
			index++;
		if (!is_sep(str[index]) && str[index] != '\0')
			count++;
		while (!is_sep(str[index]) && str[index] != '\0')
			index++;
	}
	return (count);
}

static int	word_size(char const *str, int index)
{
	int		size;

	size = 0;
	while (is_sep(str[index]) == 0 && str[index] != '\0')
	{
		size++;
		index++;
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

char		**ft_split_whitespaces(char const *s)
{
	char	**w;
	int		i;
	int		j;
	int		k;

	if (!s || (w = (char**)malloc(sizeof(char*) * (word_count(s) + 1))) == 0)
		return (NULL);
	i = -1;
	j = 0;
	while (++i < word_count(s))
	{
		while (is_sep(s[j]))
			j++;
		if ((w[i] = (char*)malloc(sizeof(char) * (word_size(s, j) + 1))) == 0)
		{
			free_loop(w, i);
			return (NULL);
		}
		k = 0;
		while (is_sep(s[j]) == 0 && s[j] != '\0')
			w[i][k++] = s[j++];
		w[i][k] = '\0';
	}
	w[word_count(s)] = NULL;
	return (w);
}
