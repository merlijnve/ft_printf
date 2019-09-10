/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test2.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 19:05:38 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/05 20:11:35 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "srcs/printf.h"

int		main(void)
{
	int i;

	i = 10;
	ft_printf("%p\n", &i);
	printf("%p\n", &i);
	//printf("int: %ld", 2147483648);
}
