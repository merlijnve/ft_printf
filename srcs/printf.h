/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:19:19 by jboer          #+#    #+#                */
/*   Updated: 2019/08/22 16:18:01 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>

/*
**	SPEC
**	0	NULL	
**	1	HH		CHAR
**	2	H		SHORT
**	3	L		LONG
**	4	LL		LONG LONG
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
	char			fid;
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
