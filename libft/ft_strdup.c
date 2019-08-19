/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 12:30:56 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/02/01 16:12:46 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*dup;
	size_t	length;
	size_t	x;

	x = 0;
	length = 1 + ft_strlen(src);
	dup = (char *)malloc(length * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (x < length)
	{
		dup[x] = src[x];
		x++;
		dup[x + 1] = '\0';
	}
	return (dup);
}
