/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 18:36:27 by elee              #+#    #+#             */
/*   Updated: 2016/11/19 19:30:50 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*multiply_scalar(t_matrix *mat, double n)
{
	t_matrix		*res;
	unsigned int	i;
	unsigned int	j;

	res = create_matrix(mat->nrows, mat->ncols, 0.0);
	i = 0;
	while (i < mat->nrows)
	{
		j = 0;
		while (j < mat->ncols)
		{
			(res->matrix)[i][j] = (mat->matrix)[i][j] * n;
			j++;
		}
		i++;
	}
	return (res);
}

t_matrix	*multiply_matrix(t_matrix *m1, t_matrix *m2)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	k;
	t_matrix		*m3;

	if (m1->ncols != m2->nrows)
		return (NULL);
	m3 = create_matrix(m1->nrows, m2->ncols, 0.0);
	i = 0;
	while (i < m1->nrows)
	{
		j = 0;
		while (j < m2->ncols)
		{
			k = 0;
			while (k < m2->nrows)
			{
				(m3->matrix)[i][j] += (m1->matrix)[i][k] * (m2->matrix)[k][i];
				k++;
			}
			j++;
		}
		i++;
	}
	return (m3);
}

t_matrix	*transpose_matrix(t_matrix *mat)
{
	t_matrix		*res;
	unsigned int	i;
	unsigned int	j;

	res = create_matrix(mat->ncols, mat->nrows, 0.0);
	i = 0;
	while (i < res->nrows)
	{
		j = 0;
		while (j < res->ncols)
		{
			(res->matrix)[i][j] = (mat->matrix)[j][i];
			j++;
		}
		i++;
	}
	return (res);
}

double		dot_prod(t_matrix *m1, t_matrix *m2)
{
	double			res;
	unsigned int	i;

	if (m1->nrows != 1 && m2->nrows != 1 && m1->ncols != m2->ncols)
		return (0.0 / 0.0);
	i = 0;
	res = 0;
	while (i < m1->ncols)
	{
		res += (m1->matrix)[0][i] * (m2->matrix)[0][i];
		i++;
	}
	return (res);
}
