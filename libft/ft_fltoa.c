/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_fltoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 15:16:20 by jboer          #+#    #+#                */
/*   Updated: 2019/09/16 19:37:50 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

static void				round_up(int j, char *str, long double f)
{
	while (str[j])
	{
		if (f >= 0.5)
		{

		}
	}
}

static void				add_prec(char *str, int prec, long double f)
{
	int					i;
	int					j;

	j = 0;
	i = 0;
	while (*str)
		str++;
	*str = '.';
	str++;
	while (prec)
	{
		f = f * (long double)10;
		i = (int)f;
		ft_putnbr(i);
		ft_putchar('\n');
		f -= (long double)i;
		str[j] = i + '0';
		prec--;
		j++;
	}
	round_up(j - 1, str, f);
}

char					*ft_fltoa(long double f, int prec)
{
	int					intlen;
	char				*str;
	long long			dec;

	if (prec == 0)
		prec = 6;
	dec = (long long)f;
	ft_putnbrlong(dec);
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
	printf("   str:   %s\n", str);
	if (prec > 0)
		add_prec(str, prec, f);
	return (str);
}
