/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_twodnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 03:16:24 by elee              #+#    #+#             */
/*   Updated: 2016/12/13 03:18:45 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		**ft_int_twodnew(int a, int b)
{
	int		**new;
	int		i;

	new = (int**)malloc(sizeof(int*) * a);
	if (!new)
		return (NULL);
	i = -1;
	while (++i < a)
		new[i] = ft_intnew(b);
	return (new);
}
