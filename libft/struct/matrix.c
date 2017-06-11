/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 15:14:13 by elee              #+#    #+#             */
/*   Updated: 2016/11/19 19:29:55 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_matrix	*create_matrix(unsigned int n, unsigned int m, double init)
{
	t_matrix		*mat;
	unsigned int	i;
	unsigned int	j;

	mat = (t_matrix*)malloc(sizeof(t_matrix));
	mat->nrows = n;
	mat->ncols = m;
	mat->matrix = (double**)malloc(sizeof(double*) * n);
	i = 0;
	while (i < n)
		mat->matrix[i++] = (double*)malloc(sizeof(double) * m);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			mat->matrix[i][j] = init;
			j++;
		}
		i++;
	}
	return (mat);
}

void		destroy_matrix(t_matrix *mat)
{
	unsigned int	i;

	i = 0;
	while (i < mat->nrows)
		free(mat->matrix[i++]);
	free(mat->matrix);
	free(mat);
}

void		print_matrix(t_matrix *mat)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < mat->nrows)
	{
		j = 0;
		while (j < mat->ncols)
		{
			(j == mat->ncols - 1) ? ft_printf("%6.2e", mat->matrix[i][j])
				: ft_printf("%6.2e ", mat->matrix[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

t_matrix	*add_matrix(t_matrix *m1, t_matrix *m2)
{
	unsigned int	i;
	unsigned int	j;
	t_matrix		*m3;

	if (m1->nrows != m2->nrows || m1->ncols != m2->ncols)
		return (NULL);
	m3 = create_matrix(m1->nrows, m1->ncols, 0.0);
	m3->nrows = m1->nrows;
	m3->ncols = m1->ncols;
	i = 0;
	while (i < m3->nrows)
	{
		j = 0;
		while (j < m3->ncols)
		{
			m3->matrix[i][j] = m1->matrix[i][j] + m2->matrix[i][j];
			j++;
		}
		i++;
	}
	return (m3);
}

t_matrix	*subtract_matrix(t_matrix *m1, t_matrix *m2)
{
	unsigned int	i;
	unsigned int	j;
	t_matrix		*m3;

	if (m1->nrows != m2->nrows || m1->ncols != m2->ncols)
		return (NULL);
	m3 = create_matrix(m1->nrows, m1->ncols, 0.0);
	m3->nrows = m1->nrows;
	m3->ncols = m1->ncols;
	i = 0;
	while (i < m3->nrows)
	{
		j = 0;
		while (j < m3->ncols)
		{
			m3->matrix[i][j] = m1->matrix[i][j] - m2->matrix[i][j];
			j++;
		}
		i++;
	}
	return (m3);
}
