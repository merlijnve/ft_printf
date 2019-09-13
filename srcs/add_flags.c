/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_flags.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 12:49:06 by jboer          #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/09/12 12:42:03 by jboer         ########   odam.nl         */
=======
/*   Updated: 2019/09/12 10:47:22 by mvan-eng      ########   odam.nl         */
>>>>>>> d4a95caa5a4dbfb891fa1b4f0aa32328b35b1f02
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static char	*add_plus(char *str)
{
	char	*buf;
	int		len;

	len = (int)ft_strlen(str);
	buf = ft_strnew(len + 2);
	buf[0] = '+';
	ft_strncpy(&buf[1], str, ft_strlen(str));
	ft_strdel(&str);
	return (buf);
}

static char	*add_space(char *str)
{
	char	*buf;
	int		len;

	len = (int)ft_strlen(str);
	buf = ft_strnew(len + 2);
	buf[0] = ' ';
	ft_strcpy(&buf[1], str);
	ft_strdel(&str);
	return (buf);
}

char		*add_flags(char *str, t_print *print)
{
	int		i;

	i = 0;
	if (print->flags[2] == 1)
	{
		while (str[i] && str[i] < '0' && str[i] > '9')
			i++;
		if (i == 0 && str[i] != '-')
			str = add_plus(str);
	}
	if (print->flags[4] && !print->flags[2])
	{
		while (str[i] && str[i] < '0' && str[i] > '9')
			i++;
		if (i == 0 && str[i] != '-')
			str = add_space(str);
	}
	return (str);
}
