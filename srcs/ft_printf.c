/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:08:46 by jboer          #+#    #+#                */
/*   Updated: 2019/08/28 15:28:44 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_print	*print;
	void	(*disp[11])(t_print *, va_list);

	va_start(ap, fmt);
	disp[0] = malloc(sizeof(*disp) * 11);
	init_disp(disp);
	print = ft_memalloc(sizeof(t_print));
	if (!print)
		exit(ME);
	print->next = NULL;
	fmtflow(print, fmt, ap);
	print_string();
}
