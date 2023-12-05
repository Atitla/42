/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:14:25 by ecunha            #+#    #+#             */
/*   Updated: 2023/12/05 14:36:50 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnbr(int nb)
{
	int				count;
	unsigned int	n;

	count = 0;
	if (nb < 0)
	{
		count += ft_putcharcount('-', 1);
		n = -nb;
	}
	else
		n = nb;
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		n %= 10;
	}
	count += ft_putcharcount(n + '0', 1);
	return (count);
}
