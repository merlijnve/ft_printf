/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_base.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 12:29:11 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/27 20:52:51 by mvan-eng      ########   odam.nl         */
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
	if ((base == 8 && str[0] == '\0') || (base == 8 && print->value != 0))
		t = ft_straddtofront(t, "0");
	else if (base == 16 && print->value != 0)
		t = ft_straddtofront(t, "0x");
	return (t);
}

static void		b_to_str(unsigned long long n, t_print *print)
{
	char		*str;
	char		*buf;
	int			base;

	print->value = n;
	base = print->fid == 'o' ? 8 : 16;
	str = ft_unbrbase(n, base);
	if (print->value == 0 && print->prec == 0)
	{
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	buf = str;
	if ((int)ft_strlen(str) < print->prec - print->flags[0])
		buf = add_precision(str, print, base);
	if (print->width > (int)ft_strlen(buf))
		buf = make_width_base(print, base, buf);
	else if (print->flags[0] == 1)
		buf = add_hash(base, str, print, buf);
	if (print->fid == 'X')
		ft_str_to_uppercase(buf);
	ft_putstr(buf);
	print->printed = ft_strlen(buf);
	ft_strdel(&buf);
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
