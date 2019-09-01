/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmtstr_loop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:21:58 by jboer          #+#    #+#                */
/*   Updated: 2019/09/01 21:28:31 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*check_width_prec(t_print *print, char *fmt)
{
	if (*fmt >= '1' && *fmt <= '9')
	{
		print->width = ft_atoi(fmt);
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
		if (*fmt == '.')
		{
			print->width = ft_atoi(fmt);
			while (*fmt >= '0' && *fmt <= '9')
				fmt++;
		}
	}
	return (fmt);
}

static char		*check_flags(t_print *print, char *fmt)
{
	while (*fmt == '#' || *fmt == '0' || *fmt == '+' || *fmt == '-' ||
	*fmt == ' ')
	{
		if (*fmt == '#')
			print->flags = 1;
		if (*fmt == '0')
			print->flags = 2;
		if (*fmt == '+')
			print->flags = 4;
		if (*fmt == '-')
			print->flags = 8;
		if (*fmt == ' ')
			print->flags = 16;
		fmt++;
	}
	return (fmt);
}

static char		*fillprint(t_print *print, char *fmt)
{
	fmt++;
	fmt = check_flags(print, fmt);
	fmt = check_width_prec(print, fmt);
	fmt = check_spec(print, fmt);
	fmt = check_fid(print, fmt);
	return (fmt);
}

void			fmtflow(t_print *print, char *fmt, va_list ap)
{
	while (ft_strchr(fmt, '%'))
	{
		while (*fmt != '%')
			fmt++;
		fmt = fillprint(print, fmt);
		if (ft_strchr(fmt, '%'))
		{
			print->next = ft_memalloc(sizeof(t_print));
			if (!print)
				exit(ME);
			print = print->next;
			print->next = NULL;
			continue;
		}
		else
			break ;
	}
}
