/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 02:50:56 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/22 13:22:41 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthexa(unsigned long nbr, int upper)
{
	int				count;
	unsigned long	n;

	count = 0;
	n = nbr;
	if (n >= 16)
	{
		count += ft_puthexa((n / 16), upper);
		count += ft_puthexa((n % 16), upper);
	}
	else
	{
		if (n < 10)
			count += ft_putcharcount(n + '0', 1);
		else
		{
			if (upper == 0)
				count += ft_putcharcount(n - 10 + 'a', 1);
			else
				count += ft_putcharcount(n - 10 + 'A', 1);
		}
	}
	return (count);
}
