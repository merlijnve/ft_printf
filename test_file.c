/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 16:20:45 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/08/19 18:15:16 by mvan-eng      ########   odam.nl         */
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

	printf("CSP:\n%s, %c, %p\n\n", s, c, &c);
	//ft_printf("%s, %c, %p", s, c, &c);
	
	return (0);
}

int		diouxx(void)
{
	char	i;
	short	s;

	s = -32769;
	i = 'a';
	printf("%d, %i, %o, %u, %x, %X\n", i, i, i, i, i, i);
	//ft_printf("%d, %i, %o, %u, %x, %X\n", i, i, i, i, i, i);
	printf("%hd, %hhi, %ho, %hhu, %hx, %hhX\n", s, i, s, i, s, i);
	return(0);
}

int		main(void)
{
	int	res[8];

	res[0] = csp();
	res[1] = diouxx();
	// res[3] = flL();
	// res[4] = perc();
	// res[5] = signs();
	// res[6] = fw();
	// res[7] = prc();
}
