/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/22 22:09:59 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 19:47:19 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putendl_fd(char const *s, int fd)
{
	int		ret;

	if (!s)
		return (0);
	ret = ft_putstr_fd(s, fd);
	ret += ft_putchar_fd('\n', fd);
	return (ret);
}
