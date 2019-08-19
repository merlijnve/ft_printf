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

void	ft_putstr(char const *s)
{
	write(1, s, ft_strlen(s));
}


int		csp(void)
{
	char c;
	char *s;
	int	i;

	i = 0;
	s = "test";
	c = '!';

	printf("%s, %c, %p", s, c, &c);
	//ft_printf("%s, %c, %p", s, c, &c);
	return (0);
}

int		main(void)
{
	int	res[8];

	res[0] = csp();
	// res[1] = diouxx();
	// res[2] = hhll();
	// res[3] = flL();
	// res[4] = perc();
	// res[5] = signs();
	// res[6] = fw();
	// res[7] = prc();
}
