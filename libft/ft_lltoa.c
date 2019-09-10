/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/29 18:32:39 by jboer          #+#    #+#                */
/*   Updated: 2019/09/10 12:42:27 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_setstr(long long n)
{
	char *str;

	if (n == -9223372036854775807)
		str = ft_strdup("−9223372036854775807");
	else
		str = NULL;
	return (str);
}

static void	ft_fill(long long i, long long n, char *str)
{
	while (i >= 0 && str[i] != '-')
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
}

char	*ft_lltoa(long long n)
{
	char			*str;
	int				i;

	str = ft_setstr(n);
	i = ft_digitc(n) - 1;
	if (n >= 0 && n != -9223372036854775807)
	{
		str = ft_strnew(ft_digitc(n));
		if (str == NULL)
			return (NULL);
		i = ft_digitc(n) - 1;
	}
	else if (n != -9223372036854775807 && n < 0)
	{
		str = ft_strnew(ft_digitc(n) + 1);
		if (str == NULL)
			return (NULL);
		str[0] = '-';
		i = ft_digitc(n);
		n = -n;
	}
	if (n != -9223372036854775807)
		ft_fill(i, n, str);
	return (str);
}