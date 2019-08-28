/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:20:45 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/08/28 17:24:32 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int		csp(void)
{
	char c;
	char *s;
	int	i;

	i = 0;
	s = "test";
	c = '!';

	printf("basic CSP:\n");
	printf("real: %s, %c, %p\n", s, c, &c);
	//ft_printf("ft_: %s, %c, %p", s, c, &c);
	
	return (0);
}

int		diouxx(void)
{
	char	i;
	short	s;

	s = -32767;
	i = 'a';
	printf("diouxX:\n");
	printf("real: %d, %i, %o, %u, %x, %X\n", i, i, i, i, i, i);
	//ft_printf("ft_: %d, %i, %o, %u, %x, %X\n", i, i, i, i, i, i);
	printf("real: %hd, %hhi, %ho, %hhu, %hx, %hhX\n", s, i, s, i, s, i);
	return(0);
}

int		perc(void)
{
	short	i;

	i = 5;
	printf("percentage:\n");
	printf("real: %d%%, %%%%%i%%%%%% %o%%\n", i, i, i);
	//ft_printf("real: %d%%, %%%%%i%%%%%% %o%%\n", i, i, i);
	return (0);
}

int		prec(void)
{
	short	s;
	float	f;
	int		i;

	s = 65;
	f = 18.73;
	i = 14709;
	printf("precision:\n");
	printf("real: %4.6d, %8.7f, %hd\n", i, f, s);
	//ft_printf("real: %4.1d, %8.7f, %hd\n", i, f, s);
	return (0);
}

int		flL()
{
	float	f;
	double	l;
	int		i;

	i = 1938;
	f = 148.382;
	l = 147123123;
	printf("long floats:\n");
	printf("real: %lf, %1.4lf, %.6i\n", f, l, i);
	return (0);
}

int		main(void)
{
	int	res[8];

	//res[0] = csp();
	res[1] = diouxx();
	//res[3] = flL();
	//res[4] = perc();
	// res[5] = signs();
	// res[6] = fw();
	//res[7] = prec();
}
