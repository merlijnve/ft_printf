/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 13:32:29 by jboer          #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/09/09 14:01:21 by jboer         ########   odam.nl         */
=======
/*   Updated: 2019/09/10 13:35:57 by mvan-eng      ########   odam.nl         */
>>>>>>> 383fb7cb2a2b7c593819f0141f492d816319887d
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *str;

	str = malloc(size + 1);
	if (str == NULL)
		return (NULL);
	ft_memset(str, '\0', size + 1);
	return (str);
}
