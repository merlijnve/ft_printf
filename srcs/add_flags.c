/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_flags.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 12:49:06 by jboer          #+#    #+#                */
/*   Updated: 2019/09/04 14:54:54 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char		*add_flags(char *str, t_print *print)
{
	char	*buf;

	if (ft_strlen(str) < print->width)
	{
		buf = ft_strnew(print->width);
		if (print->flags[3])
		{
			
		}

	
}