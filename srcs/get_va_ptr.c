/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_ptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 19:43:15 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/11 14:35:05 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**	Adds width / checks LJ for left-justify
**	LJ == 1, do left justify
*/

static char	*make_ptr_wid(int w, char *s, int lj)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(w);
	while (i < w)
	{
		res[i] = ' ';
		i++;
	}
	if (res == NULL)
		exit(1);
	if (lj == 1)
	{
		ft_strncpy(res + 2, s, 12);
		res[0] = '0';
		res[1] = 'x';
	}
	else
	{
		ft_strncpy(&res[w - 12], s, 12);
		res[w - 13] = 'x';
		res[w - 14] = '0';
	}
	return (res);
}

void		get_va_ptr(t_print *print, va_list ap)
{
	unsigned long	p;
	char			*res;
	int				i;

	i = 0;
	p = va_arg(ap, unsigned long);
	res = ft_nbrbase(p, 16);
	if (print->width > 14)
	{
		res = make_ptr_wid(print->width, res, print->flags[3]);
	}
	else
		ft_putstr("0x");
	ft_putstr(res);
	ft_strdel(&res);
}
