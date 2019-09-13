/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_perc.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 14:42:14 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/13 15:25:25 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void		print_perc(t_print *print)
{
	char	*s;
	char	c;

	c = ' ';
	if (print->flags[1] == 1 && !print->flags[3])
		c = '0';
	s = ft_strdup("%");
	if (print->width > 1)
	{
		ft_strdel(&s);
		s = ft_strnew(print->width);
		ft_memset(s, c, print->width);
		if (print->flags[3] == 1)
			s[0] = '%';
		else
			s[print->width - 1] = '%';
	}
	ft_putstr(s);
	ft_strdel(&s);
}
