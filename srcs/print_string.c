/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:21:57 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/08/28 18:48:29 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_arg(t_print *print, va_list ap)
{
	if (print->fid == 'd' || print->fid == 'i')
		get_va_int(print, ap);
	if (print->fid == 'u' || print->fid == 'o' || print->fid == 'x' ||
	print->fid == 'X')
		get_va_unsig(print, ap);
	if (print->fid == 'f')
		get_float(print, ap);
	if (print->fid == 'c')
		get_char(print, ap);
	if (print->fid == 'p')
		get_pointer(print, ap);
	if (print->fid == 's')
		get_string(print, ap);
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
// mogelijkheid om buiten de string te komen!!
		fmt++;
	}
	return (0);
}
