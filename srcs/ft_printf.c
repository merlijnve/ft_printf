/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:08:46 by jboer          #+#    #+#                */
/*   Updated: 2019/09/11 16:29:57 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void	free_struct(t_print *print)
{
	t_print *temp;

	while (print)
	{
		temp = print;
		print = print->next;
		ft_memdel((void **)&temp);
	}
	ft_memdel((void **)print);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_print	*print;
	char	*dup;

	va_start(ap, fmt);
	print = (t_print *)ft_memalloc(sizeof(t_print));
	if (!print)
		exit(1);
	print->next = NULL;
	dup = (char *)fmt;
	fmtflow(print, dup);
	print_string(print, dup, ap);
	free_struct(print);
	va_end(ap);
	return (0);
}
