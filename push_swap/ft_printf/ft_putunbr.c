/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 05:14:25 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/15 00:29:38 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunbr(unsigned int nb)
{
	int				count;
	unsigned int	n;

	count = 0;
	n = nb;
	if (n > 9)
	{
		count += ft_putnbr(n / 10);
		n %= 10;
	}
	count += ft_putcharcount(n + '0', 1);
	return (count);
}
