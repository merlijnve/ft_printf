/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 18:03:09 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/05 13:51:39 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * (size + 1));
	ft_putstr("kech\n");
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < (int)(size + 1))
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
