/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 19:39:56 by jboer          #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/09/17 18:06:22 by jboer         ########   odam.nl         */
=======
/*   Updated: 2019/09/17 17:59:55 by mvan-eng      ########   odam.nl         */
>>>>>>> 80e98dc10aab7388da889f3bb84a36fa679727b0
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_lltoa(long long int n)
{
	int		intlen;
	char	*strn;
	int		i;

	i = 0;
	intlen = ft_llintlen(n);
	strn = (char *)malloc(sizeof(char) * (intlen + 1));
	if (strn == NULL)
		return (NULL);
	strn[intlen] = '\0';
	if (n < (long long)0)
	{
		n = n * (long long)-1;
		intlen--;
		strn[i] = '-';
		i = 1;
	}
	strn = ft_longtos(strn, intlen, i, n);
	return (strn);
}
