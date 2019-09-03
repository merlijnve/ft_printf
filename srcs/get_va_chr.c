/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_chr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/30 14:45:26 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/02 16:47:04 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*make_str_wid(int w, char c, int min)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(w);
	if (res == NULL)
		exit(1);
	while (i < w)
	{
		res[i] = ' ';
		i++;
	}
	if (min == 1)
		res[0] = c;
	else
		res[w - 1] = c;
	return (res);
}

void		get_va_chr(t_print *print, va_list ap)
{
	char	c;
	char	*res;

	c = va_arg(ap, char);
	if (print->width > 1)
		res = make_str_wid(print->width, c, print->flags[3]);
	else
	{
		res = ft_strnew(1);
		if (res == NULL)
			exit(1);
		res[0] = c;
	}
	ft_putstr(res);
	ft_strdel(&res);
}
