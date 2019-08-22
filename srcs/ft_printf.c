/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:08:46 by jboer          #+#    #+#                */
/*   Updated: 2019/08/21 16:07:47 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_print *print;

	va_start(ap, fmt);
	print = ft_memalloc(sizeof(t_print));
	if (!print)
		exit(ME);
	print->next = NULL;
	fmtflow(print, fmt, ap);
}
