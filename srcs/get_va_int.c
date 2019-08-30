/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:20:24 by jboer          #+#    #+#                */
/*   Updated: 2019/08/29 18:48:50 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*i_to_str(long long n, t_print *print)
{
	char		*str;

	str = ft_lltoa(n);
	return (str);
}

char			*get_va_int(t_print *print, va_list ap)
{
	if (print->spec == 0)
		return (i_to_str((long long)va_arg(ap, int), print));
	if (print->spec == 1)
		return (i_to_str((long long)va_arg(ap, char), print));
	if (print->spec == 2)
		return (i_to_str((long long)va_arg(ap, short int), print));
	if (print->spec == 3)
		return (i_to_str((long long)va_arg(ap, long int), print));
	if (print->spec == 4)
		return (i_to_str((long long)va_arg(ap, long long), print));
	return (NULL);
}