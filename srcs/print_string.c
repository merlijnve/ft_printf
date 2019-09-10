/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:21:57 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/05 20:07:27 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_arg(t_print *print, va_list ap)
{
	if (print->fid == 'd' || print->fid == 'i')
		get_va_int(print, ap);
	// if (print->fid == 'u' || print->fid == 'o' || print->fid == 'x' ||
	// print->fid == 'X')
	// 	get_va_uns(print, ap);
	// if (print->fid == 'f')
	// 	get_va_flt(print, ap);
	if (print->fid == 'c')
		get_va_chr(print, ap);
	if (print->fid == 'p')
		get_va_ptr(print, ap);
	if (print->fid == 's')
		get_va_str(print, ap);
}

int		print_string(t_print *print, char *fmt, va_list ap)
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
		if (print)
			print = print->next;
		else
			return (0);
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
