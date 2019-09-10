/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:20:24 by jboer          #+#    #+#                */
/*   Updated: 2019/09/05 18:58:40 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char			*get_va_int(t_print *print, va_list ap)
{
	if (print->spec == 0)
		ft_putstr(ft_lltoa((long long)va_arg(ap, int)));
	if (print->spec == 1)
		ft_putstr(ft_lltoa((long long)va_arg(ap, int)));
	if (print->spec == 2)
		ft_putstr(ft_lltoa((long long)va_arg(ap, int)));
	if (print->spec == 3)
		ft_putstr(ft_lltoa((long long)va_arg(ap, long int)));
	if (print->spec == 4)
		ft_putstr(ft_lltoa((long long)va_arg(ap, long long)));
	return (NULL);
}
