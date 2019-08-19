/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 13:28:44 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/02/03 20:30:58 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_setstr(int n)
{
	char *str;

	if (n == -2147483648)
		str = ft_strdup("-2147483648");
	else
		str = NULL;
	return (str);
}

static void	ft_fill(int i, int n, char *str)
{
	while (i >= 0 && str[i] != '-')
	{
		str[i] = (n % 10) + 48;
		n = n / 10;
		i--;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		i;

	str = ft_setstr(n);
	i = ft_digitc(n) - 1;
	if (n >= 0 && n != -2147483648)
	{
		str = ft_strnew(ft_digitc(n));
		if (str == NULL)
			return (NULL);
		i = ft_digitc(n) - 1;
	}
	else if (n != -2147483648 && n < 0)
	{
		str = ft_strnew(ft_digitc(n) + 1);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		i = ft_digitc(n);
		n = -n;
	}
	if (n != -2147483648)
		ft_fill(i, n, str);
	return (str);
}
