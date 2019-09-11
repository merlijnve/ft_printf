/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_flags.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 12:49:06 by jboer          #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/09/11 17:38:07 by jboer         ########   odam.nl         */
=======
/*   Updated: 2019/09/11 12:26:40 by mvan-eng      ########   odam.nl         */
>>>>>>> 383fb7cb2a2b7c593819f0141f492d816319887d
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

<<<<<<< HEAD
static char *add_plus(char *str)
{
	char	*buf;
	int		i;
	int		len;

	len = (int)ft_strlen(str);
	i = 0;
	buf = (char *)malloc(len + (size_t)2);
	buf[len + 1] = '\0';
	buf[i] == '+';
	ft_strcpy(buf[i + 1], str);
	ft_strdel(&str);
	return (buf);
}

static char	*left_justify(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[j] && str[j] != '+' && str[j] < '0' && str[j] > '9')
		j++;
	if (j == 0)
		return (str);
	while (str[j])
	{
		str[i] = str[j];
		str[j] = ' ';
		i++;
		j++;
	}
	return (str);
}

static char	*add_zero(char *str, int p)
{
	int		i;

	i = 0;
	while (str[i] && str[i] < '0' && str[i] > '9')
	{
		str[i] = '0';
		i++;
	}
	if (p)
		str[0] = '+';
	return (str);
}

static char	*add_space(char *str, t_print *print)
{
	char	*buf;
	int		i;
	int		j;

	j = 0;
	i = 0;
	buf = str;
	if (print->check)
	{
		if (str[0] == '0')
			str[0] = ' ';
		if (str[0] >= '1' && str[0] <= '9')
		{
			j = ft_charindex(str, ' ');
			while (j > 0)
			{
				str[j] = str[j - 1];
				j--;
			}
			str[0] = ' ';
		}
	}
	buf = ft_strjoin(" ", str);
	ft_strdel(&str);
	return (str);
}

char		*add_flags(char *str, t_print *print)
{
	int		i;

	i = 0;
	if (print->flags[2])
	{
		while (str[i] && str[i] < '0' && str[i] > '9')
			i++;
		if (i == 0)
			str = add_plus(str);
		else
			str[i - 1] = '+';
	}
	if (print->flags[3] && print->width)
		str = left_justify(str);
	else if (print->flags[1])
		str = add_zeros(str, print->flags[2]);
	if (print->flags[4] && !print->flags[2])
		str = add_space(str, print);
	return (str);
}
=======
// char		*add_flags(char *str, t_print *print)
// {
// 	char	*buf;

// 	if (print->flags[2])
// 	{
		
// 	}
// 	if (print->flags[3])
// 	{

// 	}
// }
>>>>>>> 383fb7cb2a2b7c593819f0141f492d816319887d
