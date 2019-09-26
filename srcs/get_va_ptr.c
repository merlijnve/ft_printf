/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_ptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 19:43:15 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/26 14:43:36 by mvan-eng      ########   odam.nl         */
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
	int		len;

	len = (int)ft_strlen(s);
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
		ft_strncpy(res + 2, s, len);
		ft_strncpy(res, "0x", 2);
	}
	else
	{
		ft_strncpy(&res[w - len], s, len);
		ft_strncpy(&res[w - (len + 2)], "0x", 2);
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
	if (print->width > ((int)ft_strlen(res) + 2))
		res = make_ptr_wid(print->width, res, print->flags[3]);
	else
	{
		ft_putstr("0x");
		print->printed = 2;
	}
	ft_putstr(res);
	print->printed += ft_strlen(res);
	ft_strdel(&res);
}
