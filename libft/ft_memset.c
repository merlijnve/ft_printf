/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 16:52:26 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/01/27 20:08:31 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	unsigned char	*test;

	test = (unsigned char *)b;
	i = 0;
	while (len > 0)
	{
		test[i] = c;
		i++;
		len--;
	}
	return (b);
}
