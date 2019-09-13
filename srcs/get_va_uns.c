/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_uns.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 18:22:57 by jboer          #+#    #+#                */
/*   Updated: 2019/09/12 15:20:21 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*fill_width_u(char *str, t_print *print)
{
	char		*buf;
	size_t		slen;
	char		c;

	c = ' ';
	if (print->flags[1] == 1)
		c = '0';
	slen = ft_strlen(str);
	buf = ft_strnew(print->width);
	ft_memset((void *)buf, c, print->width);
	if (print->flags[3] == 1)
		ft_strncpy(buf, str, slen);
	else
		ft_strncpy(&buf[print->width - slen], str, slen);
	return (buf);
}

static void	ui_to_str(unsigned long long n, t_print *print)
{
	char	*str;
	char	*buf;

	str = ft_ulltoa(n);
	if (print->width > (int)ft_strlen(str))
	{
		buf = str;
		str = fill_width_u(str, print);
		ft_strdel(&buf);
	}
	ft_putstr(str);
	ft_strdel(&str);
}

void		get_va_uns(t_print *print, va_list ap)
{
	if (print->spec == 0)
		ui_to_str((unsigned long long)va_arg
		(ap, unsigned int), print);
	if (print->spec == 1)
		ui_to_str((unsigned long long)va_arg
		(ap, unsigned int), print);
	if (print->spec == 2)
		ui_to_str((unsigned long long)va_arg
		(ap, unsigned int), print);
	if (print->spec == 3)
		ui_to_str((unsigned long long)va_arg
		(ap, unsigned long int), print);
	if (print->spec == 4)
		ui_to_str((unsigned long long)va_arg
		(ap, unsigned long long), print);
}
