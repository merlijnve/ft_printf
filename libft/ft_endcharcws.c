/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_endcharcws.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/18 15:16:01 by jboer          #+#    #+#                */
/*   Updated: 2019/09/18 15:26:36 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_endcharcws(char *str, char c, char skip)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (*str == c || (*str == skip && str[1] == c)))
		{
			count++;
			str++;
		}
		if (*str)
			count = 0;
	}
	return (count);
}
