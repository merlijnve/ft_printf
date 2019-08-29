/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   struct_fill.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:19:02 by jboer          #+#    #+#                */
/*   Updated: 2019/08/29 12:52:05 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*check_spec(t_print *print, char *fmt)
{
	if (*fmt == 'l' || *fmt == 'L')
	{
		print->spec = 3;
		fmt++;
		if (*fmt == 'l')
		{
			print->spec = 4;
			fmt++;
		}
	}
	if (*fmt == 'h')
	{
		print->spec = 2;
		fmt++;
		if (*fmt == 'h')
		{
			print->spec = 1;
			fmt++;
		}
	}
	return (fmt);
}

char		*check_fid(t_print *print, char *fmt)
{
	if (*fmt == '%' || *fmt == 'd' || *fmt == 'i' || *fmt == 'u' ||
	*fmt == 'o' || *fmt == 'x' || *fmt == 'X' || *fmt == 'f' ||
	*fmt == 'F' || *fmt == 'e' || *fmt == 'E' || *fmt == 'g' ||
	*fmt == 'G' || *fmt == 'a' || *fmt == 'A' || *fmt == 'c' ||
	*fmt == 's' || *fmt == 'p' || *fmt == 'n')
		print->fid = *fmt;
	fmt++;
}
