/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:14:25 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/13 05:17:46 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_putnbr(int nb)
{
	int				count;
	unsigned int	n;

	count = 0;
	if (nb < 0)
	{
		count += ft_putcharcount('-');
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		ft_putnbr(n / 10);
		n %= 10;
	}
	count += ft_putcharcount(n + '0');
	return (count);
}