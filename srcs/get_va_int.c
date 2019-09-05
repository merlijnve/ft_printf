/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:20:24 by jboer          #+#    #+#                */
/*   Updated: 2019/09/04 13:14:22 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*i_to_str(long long n, t_print *print)
{
	char		*str;

	str = ft_lltoa(n);
<<<<<<< HEAD
	str = flags_to_str(str, print);
=======
	(void)print;
>>>>>>> f96804fdc7b41c7f318a21198b02fd98d92678b4
	return (str);
}

char			*get_va_int(t_print *print, va_list ap)
{
	if (print->spec == 0)
		return (i_to_str((long long)va_arg(ap, int), print));
	if (print->spec == 1)
		return (i_to_str((long long)va_arg(ap, int), print));
	if (print->spec == 2)
		return (i_to_str((long long)va_arg(ap, int), print));
	if (print->spec == 3)
		return (i_to_str((long long)va_arg(ap, long int), print));
	if (print->spec == 4)
		return (i_to_str((long long)va_arg(ap, long long), print));
	return (NULL);
}
