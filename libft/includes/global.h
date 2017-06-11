/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/07 01:09:54 by elee              #+#    #+#             */
/*   Updated: 2016/11/11 14:27:58 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GLOBAL_H
# define GLOBAL_H

typedef struct	s_uns
{
	char	spec;
	int		(*f)(size_t, int*, char*);
}				t_uns;

typedef struct	s_flo
{
	char	spec;
	int		(*f)(double, int*, char *);
}				t_flo;

t_uns			g_uns[] =
{
	{'u', &ft_putuns},
	{'U', &ft_putuns},
	{'o', &ft_putoct},
	{'O', &ft_putoct},
	{'x', &ft_puthex},
	{'X', &ft_puthex},
	{'b', &ft_putbin},
};

t_flo			g_flo[] =
{
	{'f', &ft_putf},
	{'F', &ft_putf},
	{'e', &ft_pute},
	{'E', &ft_pute},
	{'g', &ft_putg},
	{'G', &ft_putg},
	{'a', &ft_puta},
	{'A', &ft_puta},
	{'v', &ft_putv},

};

int				g_fl[8] = {0, -1, 0, 0, 0, 0, 0, 0};

#endif
