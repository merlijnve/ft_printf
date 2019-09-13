/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_width_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 11:00:28 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/13 14:17:33 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*place_prepos_zero(t_print *print, int rest, char *str, char *t)
{
	int len;

	len = ft_strlen(str);
	if (print->flags[1] == 1)
	{
		ft_strncpy(&t[print->width - len], str, len);
		if (rest == 1)
			return (t);
		ft_strncpy(t, "0x", 2);
	}
	else
	{
		if (print->flags[3] == 1)
			t = ft_strncpy(&t[rest], str, len);
		else
			t = ft_strncpy(&t[print->width - len], str, len);
		if (rest == 1)
			t[print->width - len - 4] = '0';
		else
			ft_strncpy(&t[print->width - len - 8], "0x", 2);
	}
	return (t);
}

static char		*make_width_hash(t_print *print, int rest, char *str)
{
	char	*t;
	int		len;
	char	*temp;

	len = ft_strlen(str);
	t = ft_strnew(print->width);
	temp = t;
	ft_memset((void *)t, ' ', print->width);
	if (print->flags[1] == 1 && print->flags[3] != 1)
		ft_memset((void *)t, '0', print->width);
	place_prepos_zero(print, rest, str, t);
	return (temp);
}

char			*make_width_base(t_print *print, int base, char *str)
{
	int		rest;
	char	*t;
	char	*temp;

	rest = 0;
	t = str;
	temp = NULL;
	if (print->flags[0] == 1)
		rest = base / 8;
	if (print->flags[0] == 1 && print->width - rest > (int)ft_strlen(str))
		temp = make_width_hash(print, rest, str);
	else
	{
		t = ft_strnew(print->width);
		temp = t;
		ft_memset((void *)t, ' ', print->width);
		if (print->flags[1] == 1 && print->flags[3] != 1)
			ft_memset((void *)t, '0', print->width);
		if (print->flags[3] == 1)
			t = ft_strncpy(t, str, ft_strlen(str));
		else
			t = ft_strncpy(&t[print->width - ft_strlen(str)], str,
			ft_strlen(str));
	}
	return (temp);
}
