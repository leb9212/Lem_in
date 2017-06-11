/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/01 16:11:52 by elee              #+#    #+#             */
/*   Updated: 2016/10/01 16:15:37 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_ptrnew(size_t size)
{
	char	**new;

	new = (char**)malloc(sizeof(char*) * (size + 1));
	if (new == NULL)
		return (NULL);
	ft_bnull(new, size + 1);
	return (new);
}
