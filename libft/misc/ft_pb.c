/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:45:11 by elee              #+#    #+#             */
/*   Updated: 2016/11/15 22:45:14 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	ft_pb(int power, int base)
{
	long double	result;

	result = 1.0;
	if (power == 0)
		return (result);
	else if (power > 0)
		while (power-- > 0)
			result *= base;
	else if (power < 0)
		while (power++ < 0)
			result /= base;
	return (result);
}
