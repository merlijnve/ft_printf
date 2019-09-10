/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbrbase.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 13:43:08 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/10 12:39:10 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lldigitc(long long n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int			ft_putnbrbase(long long l, int b)
{
	char	*res;
	int		l;

	l = ft_lldigitc(l);
	if (l == -9223372036854775808)
	{
		ft_putstr("-9223372036854775808");
		return (0);
	}
	if (b = 10)
	{
		res = ft_lltoa(l);
		ft_putstr(res);
		ft_strdel(&res);
	}
}
