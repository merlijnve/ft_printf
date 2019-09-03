/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:08:46 by jboer          #+#    #+#                */
/*   Updated: 2019/09/02 18:31:26 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_print	*print;
	char	*dup;

	va_start(ap, fmt);
	print = ft_memalloc(sizeof(t_print));
	if (!print)
		exit(1);
	print->next = NULL;
	dup = ft_strdup(fmt);
	fmtflow(print, dup);
	print_string(print, dup, ap);
	return (0);
}
