/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fltoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 15:16:20 by jboer          #+#    #+#                */
/*   Updated: 2019/09/17 17:47:09 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static char				*round_up(int j, char *str, long double f)
{
	int					n;
	char				*buf;

	buf = str;
	f = f * (long double)10;
	n = (int)f;
	if (n >= 5)
	{
		while (j >= 0 && (str[j] == '9' || str[j] == '.'))
		{
			if (str[j] != '.')
				str[j] = '0';
			j--;
		}
		if (j == -1)
		{
			buf = ft_strnew(ft_strlen(str) + 1);
			ft_strcpy(&buf[1], str);
			buf[0] = '1';
			ft_strdel(&str);
		}
		else
			buf[j] = buf[j] + 1;
	}
	return (buf);
}

static char				*add_prec(char *str, int prec, long double f)
{
	int					i;
	int					j;

	j = 0;
	i = 0;
	while (str[j])
		j++;
	str[j] = '.';
	j++;
	while (prec)
	{
		f = f * (long double)10;
		i = (int)f;
		f -= (long double)i;
		str[j] = i + '0';
		prec--;
		j++;
	}
	str = round_up(j - 1, str, f);
	return (str);
}

static char				*no_prec(char *str, long double f)
{
	int					i;

	i = 0;
	while (str[i])
		i++;
	str = round_up(i - 1, str, f);
	return (str);
}

char					*ft_fltoa(long double f, int prec)
{
	int					intlen;
	char				*str;
	long long			dec;

	if (prec == -1)
		prec = 6;
	dec = (long long)f;
	f -= (long double)dec;
	intlen = ft_llintlen(dec);
	str = ft_strnew(intlen + prec + 1);
	if (str == NULL)
		return (NULL);
	while (intlen > 0)
	{
		str[intlen - 1] = (dec % (long long)10) + '0';
		dec = dec / (long long)10;
		intlen--;
	}
	if (prec)
		str = add_prec(str, prec, f);
	else
		str = no_prec(str, f);
	return (str);
}
