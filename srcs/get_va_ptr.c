/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_ptr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 19:43:15 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/05 20:49:34 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**	Adds width / checks LJ for left-justify
**	LJ == 1, do left justify
*/

// static char	*make_ptr_wid(int w, char *s, int lj)
// {
// 	char	*res;
// 	int		len;
// 	int		i;

// 	i = 0;
// 	len = ft_strlen(s);
// 	res = ft_strnew(w);
// 	while (i < w)
// 	{
// 		res[i] = ' ';
// 		i++;
// 	}
// 	if (res == NULL)
// 		exit(1);
// 	if (lj == 1)
// 		ft_strncpy(res, s, len);
// 	else
// 		ft_strncpy(&res[w - len], s, len);
// 	return (res);
// }

void		get_va_ptr(t_print *print, va_list ap)
{
	unsigned long	p;

	p = va_arg(ap, unsigned long);
	(void)print;
	printf("pee: %li, hex: %lx\n", p, p);
	// if (print->width > 8)
	// {
	// 	make_ptr_wid(print->width, p, print->flags[3]);
	// }
}
