/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmtflow.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:21:58 by jboer          #+#    #+#                */
/*   Updated: 2019/08/22 12:53:31 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*check_width(t_print *print, char *fmt)
{
	if (*fmt >= '1' && *fmt <= '9')
	{
		print->width = ft_atoi(fmt);
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
	}
	return (fmt);
}

static char		*fillprint(t_print *print, char *fmt)
{
	while (!print->fid)
	{
		fmt++;
		fmt = check_flags();
		fmt = check_width();
		fmt = check_fid();
	}
}

void			fmtflow(t_print *print, char *fmt, va_list ap)
{
	int			c;

	c = 0;
	while (*fmt)
	{
		if (*fmt == '%')
			fmt = fillprint(print, fmt);
		if (ft_strchr(fmt, '%'))
		{
			print->next = ft_memalloc(sizeof(t_print));
			if (!print)
				exit(ME);
			print = print->next;
			print->next = NULL;
		}
		fmt++;
	}
}
