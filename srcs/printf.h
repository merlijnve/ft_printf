/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:19:19 by jboer          #+#    #+#                */
/*   Updated: 2019/08/21 15:17:07 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
#include "../libft/libft.h"
#include <stdarg.h>

typedef struct		s_print
{
	int				minus;
	int				plus;
	int				hash;
	int				zero;
	int				space;
	int				width;
	int				prec;
	char			flagger;
	int				conv;
	char			precs;
	char			widths;
	char			*toprint;
	struct s_print	*next;
}					t_print;

int			ft_printf(const char *fmt, ...);

#endif
