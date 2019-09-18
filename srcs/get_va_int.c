/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:20:24 by jboer          #+#    #+#                */
/*   Updated: 2019/09/18 17:51:32 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static void		move_plusmin(char *str, char c, t_print *print)
{
	int i;

	i = 0;
	if (print->flags[1] == 1 || print->flags[4] == 1)
	{
		if (print->value < 0)
			str[i] = '-';
		if (print->value > 0 && print->flags[4])
			str[i] = ' ';
		if (print->value > 0 && print->flags[2])
			str[i] = '+';
		i++;
		while (str[i] == c)
			i++;
		if (str[i] == '-' || str[i] == ' ' || str[i] == '+')
			str[i] = c;
	}
}

char			*fill_width(char *str, t_print *print)
{
	char		*buf;
	size_t		slen;
	char		c;

	c = ' ';
	if (print->flags[1] == 1 && print->flags[3] != 1)
		c = '0';
	slen = ft_strlen(str);
	buf = ft_strnew(print->width);
	ft_memset((void *)buf, c, print->width);
	if (print->flags[3] == 1)
		ft_strncpy(buf, str, slen);
	else
		ft_strncpy(&buf[print->width - slen], str, slen);
	move_plusmin(buf, c, print);
	ft_strdel(&str);
	return (buf);
}

static char		*add_precision(char *str, t_print *print)
{
	int		len;
	char	*res;
	char	*head;

	len = ft_strlen(str);
	if (len >= print->prec)
		return (str);
	res = ft_strnew(print->prec);
	head = res;
	res = ft_memset(res, '0', print->prec);
	res = ft_strncpy(&res[print->prec - len], str, len);
	ft_strdel(&str);
	return (head);
}

static void		i_to_str(long long n, t_print *print)
{
	char		*str;
	char		*t;

	str = ft_lltoa(n);
	print->value = n;
	t = add_flags(str, print);
	str = t;
	if ((int)ft_strlen(str) < print->prec)
		str = add_precision(str, print);
	if (print->width > (int)ft_strlen(str))
		str = fill_width(str, print);
	ft_putstr(str);
	print->printed = ft_strlen(str);
}

void			get_va_int(t_print *print, va_list ap)
{
	if (print->spec == 0)
		i_to_str((int)va_arg(ap, int), print);
	if (print->spec == 1)
		i_to_str((char)va_arg(ap, int), print);
	if (print->spec == 2)
		i_to_str((short)va_arg(ap, int), print);
	if (print->spec == 3)
		i_to_str((long)va_arg(ap, long int), print);
	if (print->spec == 4)
		i_to_str(va_arg(ap, long long), print);
}
