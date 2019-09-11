/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_int.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/28 17:20:24 by jboer          #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/09/11 16:35:19 by jboer         ########   odam.nl         */
=======
/*   Updated: 2019/09/11 12:27:56 by mvan-eng      ########   odam.nl         */
>>>>>>> 383fb7cb2a2b7c593819f0141f492d816319887d
/*                                                                            */
/* ************************************************************************** */

// #include "printf.h"

// static char		*add_spaces(char *str, t_print *print)
// {
// 	char		*buf;
// 	int			i;

<<<<<<< HEAD
	buf = ft_strnew((size_t)print->width);
	ft_memset(buf, ' ', print->width);
	i = print->width - ft_strlen(str);
	while (buf[i])
	{
		buf[i] = *str;
		str++;
		i++;
	}
	ft_memdel(&str);
	print->check = 1;
	return (buf);
}
=======
// 	buf = ft_strnew((size_t)print->width);
// 	ft_memset(buf, ' ', print->width);
// 	i = print->width - ft_strlen(str);
// 	while (buf[i])
// 	{
// 		buf[i] = *str;
// 		str++;
// 		i++;
// 	}
// 	ft_memdel(&str);
// 	return (buf);
// }
>>>>>>> 383fb7cb2a2b7c593819f0141f492d816319887d

// static char		*i_to_str(long long n, t_print *print)
// {
// 	char		*str;

// 	str = ft_lltoa(n);
// 	if (print->width > ft_strlen(str))
// 		str = add_spaces(str, print->width);
// 	str = add_flags(str, print);
// 	(void)print;
// 	return (str);
// }

// void			get_va_int(t_print *print, va_list ap)
// {
// 	if (print->spec == 0)
// 		ft_putstr(i_to_str((long long)va_arg(ap, int), print));
// 	if (print->spec == 1)
// 		ft_putstr(i_to_str((long long)va_arg(ap, int), print));
// 	if (print->spec == 2)
// 		ft_putstr(i_to_str((long long)va_arg(ap, int), print));
// 	if (print->spec == 3)
// 		ft_putstr(i_to_str((long long)va_arg(ap, long int), print));
// 	if (print->spec == 4)
// 		ft_putstr(i_to_str((long long)va_arg(ap, long long), print));
// }
