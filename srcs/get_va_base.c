/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_base.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 12:29:11 by mvan-eng       #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/09/27 17:55:25 by jboer         ########   odam.nl         */
=======
/*   Updated: 2019/09/27 16:38:44 by mvan-eng      ########   odam.nl         */
>>>>>>> 427777376239ba9864851b013971c8f54300a356
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char		*add_precision(char *str, t_print *print, int base)
{
	int		len;
	char	*res;
	char	*head;

	len = ft_strlen(str);
	if (len >= print->prec)
		return (str);
	if (base == 8)
	{
		res = ft_strnew(print->prec - print->flags[0]);
		head = res;
		res = ft_memset(res, '0', print->prec - print->flags[0]);
		ft_strncpy(&res[print->prec - len - print->flags[0]], str, len);
	}
	else
	{
		res = ft_strnew(print->prec);
		head = res;
		res = ft_memset(res, '0', print->prec);
		ft_strncpy(&res[print->prec - len], str, len);
	}
	return (head);
}

static char		*add_hash(int base, char *str, t_print *print, char *t)
{
	char	*buf;

	buf = NULL;
	if (base == 8 && print->value != 0)
		buf = ft_strjoin("0", t);
	if (base == 8 && !*str)
		buf = ft_strjoin("0", t);
	else if (base == 16 && print->value != 0)
		buf = ft_strjoin("0x", t);
	return (buf);
}

static void		b_to_str(unsigned long long n, t_print *print)
{
	char	*str;
	char	*t;
	int		base;

	print->value = n;
	base = print->fid == 'o' ? 8 : 16;
	str = ft_nbrbase(n, base);
	if (print->value == 0 && print->prec == 0)
	{
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	t = str;
	if ((int)ft_strlen(str) < print->prec - print->flags[0])
		t = add_precision(str, print, base);
	if (print->width > (int)ft_strlen(t))
		t = make_width_base(print, base, t);
	else if (print->flags[0] == 1)
		t = add_hash(base, str, print, t);
	ft_strdel(&str);
	if (print->fid == 'X')
		ft_str_to_uppercase(t);
	ft_putstr(t);
	print->printed = ft_strlen(t);
}

void			get_va_base(t_print *print, va_list ap)
{
	if (print->spec == 0)
		b_to_str((unsigned int)va_arg(ap, unsigned int), print);
	if (print->spec == 1)
		b_to_str((unsigned char)va_arg(ap, unsigned int), print);
	if (print->spec == 2)
		b_to_str((unsigned short)va_arg(ap, unsigned int), print);
	if (print->spec == 3)
		b_to_str(va_arg(ap, unsigned long), print);
	if (print->spec == 4)
		b_to_str(va_arg(ap, unsigned long long), print);
}
