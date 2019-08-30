/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:21:57 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/08/30 14:47:43 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_arg(t_print *print, va_list ap)
{
	if (print->fid == 'd' || print->fid == 'i')
		ft_putstr(get_va_int(print, ap));
	if (print->fid == 'u' || print->fid == 'o' || print->fid == 'x' ||
	print->fid == 'X')
		ft_putstr(get_va_uns(print, ap));
	if (print->fid == 'f')
		ft_putstr(get_va_flt(print, ap));
	if (print->fid == 'c')
		ft_putstr(get_va_chr(print, ap));
	if (print->fid == 'p')
		ft_putstr(get_va_ptr(print, ap));
	if (print->fid == 's')
		ft_putstr(get_va_str(print, ap));
}

int	print_string(t_print *print, char *fmt, va_list ap)
{
	while (*fmt)
	{
		while (*fmt && *fmt != '%')
		{
			ft_putchar(*fmt);
			fmt++;
		}
		if (!*fmt)
			return (0);
		print_arg(print, ap);
		ft_putstr(print->toprint);
		print = print->next;
		while (*fmt != 'd' && *fmt != 'i' && *fmt != 'o' && *fmt != 'x'
		&& *fmt != 'u' && *fmt != 'X' && *fmt != 's' && *fmt != 'c'
		&& *fmt != 'p' && *fmt)
			fmt++;
		if (!*fmt)
			return (0);
		fmt++;
	}
	return (0);
}
