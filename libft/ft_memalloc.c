/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memalloc.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 13:17:15 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/01/23 16:38:09 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	int *res;

	res = (int *)malloc(size);
	if (res == NULL)
		return (NULL);
	while (size > 0)
	{
		res[size - 1] = 0;
		size--;
	}
	return ((void *)res);
}
