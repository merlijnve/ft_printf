/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_base.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 12:29:11 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/18 17:53:03 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		b_to_str(long long n, t_print *print)
{
	char	*str;
	char	*t;
	int		base;

	print->value = n;
	base = print->fid == 'o' ? 8 : 16;
	str = ft_nbrbase(n, base);
	t = str;
	if (print->width > (int)ft_strlen(str))
		t = make_width_base(print, base, str);
	else
	{
		if (print->flags[0] == 1 && base == 8 && print->value != 0)
			t = ft_strjoin("0", str);
		else if (print->flags[0] == 1 && base == 16 && print->value != 0)
			t = ft_strjoin("0x", str);
	}
	ft_strdel(&str);
	if (print->fid == 'X')
		ft_str_to_uppercase(t);
	ft_putstr(t);
	print->printed = ft_strlen(t);
}

void			get_va_base(t_print *print, va_list ap)
{
	if (print->spec == 0)
		b_to_str((unsigned int)va_arg(ap, unsigned int), print);
	if (print->spec == 1)
		b_to_str((unsigned char)va_arg(ap, unsigned int), print);
	if (print->spec == 2)
		b_to_str((unsigned short)va_arg(ap, unsigned int), print);
	if (print->spec == 3)
		b_to_str((unsigned long)va_arg(ap, unsigned long int), print);
	if (print->spec == 4)
		b_to_str((unsigned long long)va_arg(ap, unsigned long long), print);
}
