/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_flt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 18:11:16 by jboer          #+#    #+#                */
/*   Updated: 2019/09/17 15:15:21 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		flt_to_str(long double f, t_print *print)
{
	char		*str;
	char		*buf;

	str = ft_fltoa(f, print->prec);
	
}

void			get_va_flt(t_print *print, va_list ap)
{
	if (print->spec == 0 || print->spec == 3)
		flt_to_str((long double)va_arg(ap, double), print);
	if (print->spec == 5)
		flt_to_str(va_arg(ap, long double), print);
}
