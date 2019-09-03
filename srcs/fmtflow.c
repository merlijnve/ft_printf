/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmtflow.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:21:58 by jboer          #+#    #+#                */
/*   Updated: 2019/09/02 19:01:29 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void			fmtflow(t_print *print, char *fmt)
{
	while (ft_strchr(fmt, '%'))
	{
		while (*fmt != '%')
			fmt++;
		fmt = fill_struct(print, fmt);
		if (ft_strchr(fmt, '%'))
		{
			print->next = ft_memalloc(sizeof(t_print));
			if (!print)
				exit(1);
			print = print->next;
			print->next = NULL;
			continue;
		}
		else
			break ;
	}
}
