/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fltoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 13:02:13 by jboer          #+#    #+#                */
/*   Updated: 2019/09/18 17:47:25 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*round_up(char *str, int prec, long double f, int neg)
{
	int			n;

	while (prec > -1)
	{
		f = f * (long double)10;
		prec--;
	}
	n = (int)f;
	if (n % 10 >= 5 || n % 10 <= -5)
	{
		n = ft_strlen(str);
		while (n > 0 && (str[n - 1] == '9' || str[n - 1] == '.'))
		{
			if (str[n - 1] != '.')
				str[n - 1] = '0';
			n--;
		}
		if (n == 0 && neg == 1)
			str = ft_straddtofront(str, "-1");
		if (n == 0 && neg == 0)
			str = ft_straddtofront(str, "1");
		else if (n)
			str[n - 1] = str[n - 1] + 1;
	}
	return (str);
}

static void		add_prec(char *str, int prec, long double f)
{
	int			dec;
	int			i;

	dec = 0;
	i = 0;
	while (str[i])
		i++;
	str[i] = '.';
	i++;
	while (prec)
	{
		f = f * (long double)10;
		dec = (int)f;
		f -= (long double)dec;
		str[i] = dec + '0';
		prec--;
		i++;
	}
}

static int		fl_neg(char *str, int prec, long long dec, long double f)
{
	int			intlen;

	intlen = ft_llintlen(dec);
	dec = -dec;
	f = -f;
	str[0] = '-';
	f -= (long double)dec;
	while (intlen > 1)
	{
		str[intlen - 1] = dec % (long long)10 + '0';
		dec = dec / (long long)10;
		intlen--;
	}
	if (prec)
		add_prec(str, prec, f);
	return (1);
}

static void		fl_pos(char *str, int prec, long long dec, long double f)
{
	int			intlen;

	intlen = ft_llintlen(dec);
	f -= (long double)dec;
	while (intlen > 0)
	{
		str[intlen - 1] = dec % (long long)10 + '0';
		dec = dec / (long long)10;
		intlen--;
	}
	if (prec)
		add_prec(str, prec, f);
}

char			*ft_fltoa(long double f, int prec)
{
	char		*str;
	long long	dec;
	int			neg;

	neg = 0;
	if (prec == -1)
		prec = 6;
	dec = (long long)f;
	str = ft_strnew(ft_llintlen(dec) + prec + 1);
	if (str == NULL)
		return (NULL);
	if (f == (double long)-0.0)
	{
		str[0] = '-';
		str[1] = '0';
		add_prec(str, prec, f);
	}
	if (dec < 0)
		neg = fl_neg(str, prec, dec, f);
	else if (f != (double long)-0.0)
		fl_pos(str, prec, dec, f);
	str = round_up(str, prec, f, neg);
	return (str);
}
