/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elee <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 19:00:49 by elee              #+#    #+#             */
/*   Updated: 2016/11/16 21:42:16 by elee             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "global.h"

static int	uns_func(size_t uns, int fl[8], char *s)
{
	int		index;
	char	spec;
	int		(*f)(size_t, int *, char *);

	spec = sp(s);
	index = 0;
	f = NULL;
	while (index < 7)
	{
		if (spec == g_uns[index].spec)
		{
			f = g_uns[index].f;
			break ;
		}
		index++;
	}
	return (f(uns, fl, s));
}

static int	flo_func(double flo, int fl[8], char *s)
{
	int		index;
	char	spec;
	int		(*f)(double, int *, char *);

	spec = sp(s);
	index = 0;
	f = NULL;
	while (index < 9)
	{
		if (spec == g_flo[index].spec)
		{
			f = g_flo[index].f;
			break ;
		}
		index++;
	}
	return (f(flo, fl, s));
}

static int	arg_parser(char *s, int fl[8], va_list *args, int len)
{
	if (sp(s) == 'p')
		return (ft_putp(va_arg(*args, void*), fl));
	else if (sp(s) == 'n')
		return (ft_putn(va_arg(*args, int*), len));
	else if (sp(s) == 'S' || !ft_strncmp(s, "ls", 2))
		return (ft_putcaps(va_arg(*args, wchar_t*), fl));
	else if (sp(s) == 's')
		return (ft_puts(va_arg(*args, char*), fl));
	else if (sp(s) == 'r')
		return (ft_putr(va_arg(*args, char*), fl));
	else if (sp(s) == 'C' || !ft_strncmp(s, "lc", 2))
		return (ft_putcapc(va_arg(*args, wchar_t), fl));
	else if (sp(s) == 'c')
		return (ft_putc(va_arg(*args, int), fl));
	else if (sp(s) == 'd' || sp(s) == 'D' || sp(s) == 'i')
		return (ft_putdec(va_arg(*args, intmax_t), fl, s));
	else if (sp(s) == 'u' || sp(s) == 'U' || sp(s) == 'o' || sp(s) == 'O' ||
			sp(s) == 'x' || sp(s) == 'X' || sp(s) == 'b')
		return (uns_func(va_arg(*args, size_t), fl, s));
	else if (sp(s) == 'f' || sp(s) == 'F' || sp(s) == 'e' || sp(s) == 'E' ||
			sp(s) == 'g' || sp(s) == 'G' || sp(s) == 'a' || sp(s) == 'A'
			|| sp(s) == 'v')
		return (flo_func(va_arg(*args, double), fl, s));
	return (ft_putextra(sp(s), fl));
}

static void	parser(char **format, int fl[8], va_list *args)
{
	*format += flag_parser(*format, fl);
	*format += mfw_parser(*format, fl, args);
	*format += prec_parser(*format, fl, args);
}

int			ft_printf(const char *format, ...)
{
	int		len;
	int		fl[8];
	int		error;
	va_list	args;
	va_list	copy;

	len = 0;
	va_start(args, format);
	va_copy(copy, args);
	while (*format)
	{
		while (*format && *format != '%' && len++ >= 0)
			ft_putchar(*format++);
		if (*format++ == '\0')
			return (len);
		format += pos_parser((char*)format, &args, copy);
		parser((char**)(&format), fl, &args);
		if ((error = arg_parser((char*)(format), fl, &args, len)) == -1)
			return (-1);
		len += error;
		format += mp((char*)format);
		(*format) ? format++ : 0;
	}
	va_end(args);
	return (len);
}
