/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/23 14:21:01 by elee              #+#    #+#             */
/*   Updated: 2016/09/25 23:41:51 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_starstrlen(char **tab)
{
	int		len;

	len = 0;
	while (tab[len])
		len++;
	return (len);
}

static int	ft_totallen(char **tab, int l_t)
{
	int		total_len;
	int		i;

	total_len = 0;
	i = 0;
	while (i < l_t)
	{
		total_len += (int)ft_strlen(tab[i]);
		i++;
	}
	return (total_len);
}

static char	*ft_loop(char **tab, char *sep, char *final)
{
	int		i;
	int		j;
	int		k;
	int		l;

	i = 0;
	k = 0;
	while (i < ft_starstrlen(tab))
	{
		j = 0;
		while (++j < (int)ft_strlen(tab[i]) + 1)
		{
			final[k] = tab[i][j - 1];
			k++;
		}
		l = 0;
		while (++l < (int)ft_strlen(sep) + 1 && i < ft_starstrlen(tab) - 1)
		{
			final[k] = sep[l - 1];
			k++;
		}
		i++;
	}
	final[k] = '\0';
	return (final);
}

char		*ft_join(char **tab, char *sep)
{
	char	*final;
	int		total_len;
	int		l_s;
	int		l_t;

	if (tab == NULL || sep == NULL)
		return (NULL);
	l_s = (int)ft_strlen(sep);
	l_t = ft_starstrlen(tab);
	total_len = ft_totallen(tab, l_t);
	final = (char*)malloc(sizeof(char) * (total_len + (l_t - 1) * l_s + 1));
	final = ft_loop(tab, sep, final);
	return (final);
}
