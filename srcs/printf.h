 /* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:19:19 by jboer          #+#    #+#                */
/*   Updated: 2019/09/05 19:49:08 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

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
**	saved as ascii value
*/

typedef struct		s_print
{
	int				flags[5];
	int				width;
	int				prec;
	char			fid;
	int				spec;
	int				check;
	long long		value;
	char			*toprint;
	struct s_print	*next;
}					t_print;


int					ft_printf(const char *fmt, ...);
void				fmtstr_loop(t_print *print, char *fmt, va_list ap);
void				get_va_chr(t_print *print, va_list ap);
void				fmtflow(t_print *print, char *fmt);
int					print_string(t_print *print, char *fmt, va_list ap);
char				*fill_struct(t_print *print, char *fmt);
void				get_va_int(t_print *print, va_list ap);
char				*ft_lltoa(long long n);
void				get_va_str(t_print *print, va_list ap);
void				get_va_ptr(t_print *print, va_list ap);
char				*add_flags(char *str, t_print *print);
char				*fill_width(char *str, t_print *print);
void				get_va_uns(t_print *print, va_list ap);

#endif
