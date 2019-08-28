/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:21:57 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/08/28 15:13:58 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_arg()
{
	
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
		print_arg();
		ft_putstr(print->toprint);
		print = print->next;
		while (*fmt != 'd' && *fmt != 'i' && *fmt != 'o' && *fmt != 'x'
		&& *fmt != 'u' && *fmt != 'X' && *fmt != 's' && *fmt != 'c'
		&& *fmt != 'p' && *fmt)
			fmt++;
		fmt++;
	}
	return (0);
}
