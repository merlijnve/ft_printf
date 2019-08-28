/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:20:24 by jboer          #+#    #+#                */
/*   Updated: 2019/08/28 19:02:24 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	get_va_int(t_print *print, va_list ap)
{
	if (print->spec == 1)
		itostr(va_arg(ap, char), print);
	if (print->spec == 2)
		itostr(va_arg(ap, short int), print);
	if (print->spec == 3)
		itostr(va_arg(ap, long int), print);

}