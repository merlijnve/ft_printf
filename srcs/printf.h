/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:19:19 by jboer          #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/09/02 19:01:41 by mvan-eng      ########   odam.nl         */
=======
<<<<<<< HEAD
/*   Updated: 2019/09/02 17:43:31 by jboer         ########   odam.nl         */
=======
/*   Updated: 2019/09/02 17:33:05 by mvan-eng      ########   odam.nl         */
>>>>>>> c9d4c7482f201020032d568f002116739ca7e1b0
>>>>>>> 90b6bb9a4061d44d44b83f2863126ee7a57d720e
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
** [0]	HASH
** [1]	ZERO
** [2]	PLUS
** [3]	MINUS
** [4]	SPACE
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
	int				flags[5];
	int				width;
	int				prec;
	char			fid;
	int				spec;
	char			*toprint;
	struct s_print	*next;
}					t_print;

int			ft_printf(const char *fmt, ...);
<<<<<<< HEAD
=======
void		fmtstr_loop(t_print *print, char *fmt, va_list ap);
<<<<<<< HEAD

#define ME			2
=======
>>>>>>> 90b6bb9a4061d44d44b83f2863126ee7a57d720e
void		get_va_chr(t_print *print, va_list ap);
void		fmtflow(t_print *print, char *fmt);
int			print_string(t_print *print, char *fmt, va_list ap);
<<<<<<< HEAD
char		*fill_struct(t_print *print, char *fmt);
=======
>>>>>>> c9d4c7482f201020032d568f002116739ca7e1b0
>>>>>>> 90b6bb9a4061d44d44b83f2863126ee7a57d720e

#endif
