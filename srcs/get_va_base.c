/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_base.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 12:29:11 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/25 12:11:42 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
	return (head);
}

static void		b_to_str(long long n, t_print *print)
{
	char	*str;
	char	*t;
	int		base;

	print->value = n;
	base = print->fid == 'o' ? 8 : 16;
	str = ft_nbrbase(n, base);
	if (print->value == 0 && print->prec == 0)
		str = ft_strnew(0);
	t = str;
	if ((int)ft_strlen(str) < print->prec)
		t = add_precision(str, print);
	if (print->width > (int)ft_strlen(t))
		t = make_width_base(print, base, t);
	else
	{
		//printf("\nprint->value: %lld\n", print->value);
		if (print->flags[0] == 1 && base == 8)
			t = ft_strjoin("0", str);
		else if (print->flags[0] == 1 && base == 16)
			t = ft_strjoin("0x", str);
	}
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
		b_to_str((unsigned long)va_arg(ap, unsigned long int), print);
	if (print->spec == 4)
		b_to_str((unsigned long long)va_arg(ap, unsigned long long), print);
}
