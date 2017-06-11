/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strresub.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 23:11:00 by elee              #+#    #+#             */
/*   Updated: 2016/11/01 23:12:03 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strresub(char *lines, size_t start)
{
	size_t	len;
	char	*tmp;

	len = ft_strlen(lines);
	tmp = ft_strdup(lines);
	ft_bzero(lines, len);
	free(lines);
	lines = ft_strnew(len - start);
	ft_strncpy(lines, &tmp[start], len - start);
	ft_bzero(tmp, len);
	free(tmp);
	return (lines);
}
