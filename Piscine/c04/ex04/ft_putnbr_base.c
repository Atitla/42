/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 14:24:39 by ecunha            #+#    #+#             */
/*   Updated: 2022/09/20 12:26:11 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	else
	{
		while (base[i])
		{
			j = i + 1;
			while (base[j])
			{
				if (base[i] == base[j] || (base[i] == '-' || base[i] == '+'))
					return (0);
				j++;
			}
			i++;
		}
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	n;
	unsigned int	i;

	if (check_base(base) == 1)
	{
		i = 0;
		while (base[i])
			i++;
		if (nbr < 0)
		{
			ft_putchar('-');
			n = -nbr;
		}
		else
			n = nbr;
		if (n >= i)
		{
			ft_putnbr_base(n / i, base);
			n %= i;
		}
		ft_putchar(base[n]);
	}
}
//#include <stdlib.h>
//int main(int argc, char **argv)
//{
//	(void) argc;
//	ft_putnbr_base(atoi(argv[1]), argv[2]);
//}