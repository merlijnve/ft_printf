/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_flt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 18:11:16 by jboer          #+#    #+#                */
/*   Updated: 2019/09/17 17:56:14 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*fill_width_f(char *str, t_print *print)
{
	char		*buf;
	size_t		slen;
	char		c;

	c = ' ';
	if (print->flags[1] == 1)
		c = '0';
	slen = ft_strlen(str);
	buf = ft_strnew(print->width);
	ft_memset((void *)buf, c, print->width);
	if (print->flags[3] == 1)
		ft_strncpy(buf, str, slen);
	else
		ft_strncpy(&buf[print->width - slen], str, slen);
	return (buf);
}

static void		flt_to_str(long double f, t_print *print)
{
	char		*str;
	char		*buf;

	str = ft_fltoa(f, print->prec);
	if (print->width > (int)ft_strlen(str))
	{
		buf = str;
		str = fill_width_f(str, print);
		ft_strdel(&buf);
	}
	ft_putstr(str);
	ft_strdel(&str);
}

void			get_va_flt(t_print *print, va_list ap)
{
	if (print->spec == 0 || print->spec == 3)
		flt_to_str((long double)va_arg(ap, double), print);
	if (print->spec == 5)
		flt_to_str(va_arg(ap, long double), print);
}
