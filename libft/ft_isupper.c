/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isupper.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 20:10:38 by mvan-eng       #+#    #+#                */
/*   Updated: 2019/01/30 20:09:06 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_isupper(int c)
{
	if (c > 64 && c < 91)
		return (1);
	else
		return (0);
}
