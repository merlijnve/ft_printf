/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 19:05:38 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/11 16:42:33 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "srcs/printf.h"

int		main(void)
{
	int i;
	char	*s;

	i = 10;
	printf("%x, %X", 255, 255);
	s = ft_strdup("testi84351ng\0");
	ft_putendl(s);
	ft_str_to_uppercase(s);
	ft_putendl(s);
	//ft_printf("mijn: %p, %c,  s\n", &i, 'a', "tering");
	//ft_printf("mijn: %12p, %15c, %18s\n", &i, 'a', "tering");
	//ft_printf("mijn: %-12p, %-15c, %-18s\n", &i, 'a', "tering");
}
