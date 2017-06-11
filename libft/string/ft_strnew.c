/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 19:17:06 by elee              #+#    #+#             */
/*   Updated: 2016/09/26 21:51:27 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new;

	new = (char*)malloc(sizeof(char) * (size + 1));
	if (new == NULL)
		return (NULL);
	ft_bzero(new, size + 1);
	return (new);
}
