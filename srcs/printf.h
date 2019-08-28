/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:19:19 by jboer          #+#    #+#                */
/*   Updated: 2019/08/28 17:30:53 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>

/*
**	SPEC
**	0	NULL	
**	1	hh		CHAR
**	2	h		SHORT
**	3	l		LONG
**	4	ll		LONG LONG
**	5	L		LONG DOUBLE
*/

/*
**	FID
**	c	0
**	s	1
**	p	2
**	d	3
**	i	4
**	o	5
**	u	6
**	x	7
**	X	8
**	f	10
**	%%	11
*/

typedef struct		s_print
{
	int				minus;
	int				plus;
	int				hash;
	int				zero;
	int				space;
	int				width;
	int				prec;
	int				fid;
	int				spec;
	char			precs;
	char			widths;
	char			*toprint;
	struct s_print	*next;
}					t_print;

int			ft_printf(const char *fmt, ...);
void		fmtflow(t_print *print, char *fmt, va_list ap);

#define ME			2

#endif
