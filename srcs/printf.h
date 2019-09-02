/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:19:19 by jboer          #+#    #+#                */
/*   Updated: 2019/09/02 15:58:59 by mvan-eng      ########   odam.nl         */
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
** FLAGS
** 0	NULL
** 1	HASH
** 2	ZERO
** 4	PLUS
** 8	MINUS
** 16	SPACE
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
	int				flags[4];
	int				width;
	int				prec;
	char			fid;
	int				spec;
	char			*toprint;
	struct s_print	*next;
}					t_print;

int			ft_printf(const char *fmt, ...);
void		fmtstr_loop(t_print *print, char *fmt, va_list ap);
char		*get_va_chr();

#define ME			2

#endif
