/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_chr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/30 14:45:26 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/05 19:25:01 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**	Adds width / checks LJ for left-justify
**	LJ == 1, do left justify
*/

static char	*make_chr_wid(int w, char c, int lj)
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
	if (lj == 1)
		res[0] = c;
	else
		res[w - 1] = c;
	return (res);
}

void		get_va_chr(t_print *print, va_list ap)
{
	int		c;
	char	*s;

	c = va_arg(ap, int);
	if (print->width > 1)
	{
		s = make_chr_wid(print->width, c, print->flags[3]);
		ft_putstr(s);
		ft_strdel(&s);
	}
	else
		ft_putchar(c);
}
