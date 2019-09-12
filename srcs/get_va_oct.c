/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_oct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 12:29:11 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/12 12:38:34 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		o_to_str(long long n, t_print *print)
{
	char	*str;
	char	*t;

	str = ft_nbrbase(n, 8);
	t = str;
	if (print->flags[0] == 1)
		t = ft_strjoin("0", str);
	ft_putstr(t);
	ft_strdel(&str);
}

void			get_va_oct(t_print *print, va_list ap)
{
	ft_putnbr(print->spec);
	if (print->spec == 0)
		o_to_str((long long)va_arg(ap, int), print);
	if (print->spec == 1)
		o_to_str((long long)va_arg(ap, int), print);
	if (print->spec == 2)
		o_to_str((long long)va_arg(ap, int), print);
	if (print->spec == 3)
		o_to_str((long long)va_arg(ap, long int), print);
	if (print->spec == 4)
		o_to_str((long long)va_arg(ap, long long), print);
}
