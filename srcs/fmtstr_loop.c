/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmtstr_loop.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:21:58 by jboer          #+#    #+#                */
/*   Updated: 2019/09/02 13:48:43 by jboer         ########   odam.nl         */
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
			print->flags[0] = 1;
		if (*fmt == '0')
			print->flags[1] = 1;
		if (*fmt == '+')
			print->flags[2] = 1;
		if (*fmt == '-')
			print->flags[3] = 1;
		if (*fmt == ' ')
			print->flags[4] = 1;
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
