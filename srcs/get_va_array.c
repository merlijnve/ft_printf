/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_array.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 16:40:51 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/09/28 18:00:18 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

/*
**	Prints out (2d) arrays
**	Needs amount of rows and defaults to 1
*/

static void	print_row(int *row, unsigned int columns, t_print *print)
{
	unsigned int	i;
	char			spaces[50];
	int				c;

	c = print->flags[1] ? '0' : ' ';
	i = 0;
	while (i < 50)
	{
		spaces[i] = c;
		i++;
	}
	spaces[49] = '\0';
	i = 0;
	while (i < columns)
	{
		ft_putchar('[');
		ft_putstr(&spaces[50 + ft_digitc(row[i]) - print->width]);
		ft_putnbr(row[i]);
		ft_putchar(']');
		i++;
	}
}

static void	get_va_int_array(t_print *print, va_list ap)
{
	int				**ar;
	unsigned int	i;
	unsigned int	columns;
	unsigned int	rows;

	i = 0;
	ar = va_arg(ap, int **);
	columns = va_arg(ap, unsigned int);
	rows = va_arg(ap, unsigned int);
	while (i < rows)
	{
		print_row(ar[i], columns, print);
		ft_putchar('\n');
		i++;
	}
}

static void	get_va_char_array(va_list ap)
{
	char			**ar;
	unsigned int	rows;
	unsigned int	i;

	i = 0;
	ar = va_arg(ap, char **);
	rows = va_arg(ap, unsigned int);
	while (i < rows)
	{
		ft_putendl(ar[i]);
		i++;
	}
}

void		get_va_array(t_print *print, va_list ap)
{
	if (print->flags[0])
		get_va_int_array(print, ap);
	else
		get_va_char_array(ap);
}
