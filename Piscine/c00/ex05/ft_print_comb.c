/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:10:02 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/07 13:29:10 by ecunha           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_result(int i, int j, int k)
{
	char	result;

	result = i + 48;
	write(1, &result, 1);
	result = j + 48;
	write(1, &result, 1);
	result = k + 48;
	write(1, &result, 1);
	if (i != 7 || j != 8 || k != 9)
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	int	m;
	int	n;
	int	o;

	m = 0;
	while (m <= 7)
	{
		n = m + 1;
		while (n <= 8)
		{
			o = n + 1;
			while (o <= 9)
			{
				ft_result(m, n, o);
				o++;
			}
			n++;
		}
		m++;
	}
}
