/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 20:48:23 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 20:48:33 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_modf(double n, double *iptr)
{
	double	absvalue;

	if ((absvalue = (n >= 0.0) ? n : -n) >= MAXPOWTWO)
		*iptr = n;
	else
	{
		*iptr = absvalue + MAXPOWTWO;
		*iptr -= MAXPOWTWO;
		while (*iptr > absvalue)
			*iptr -= 1.0;
		if (n < 0.0)
			*iptr = -*iptr;
	}
	return (n - *iptr);
}
