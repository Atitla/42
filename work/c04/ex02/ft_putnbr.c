/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 11:27:01 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/13 01:31:57 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

//void	ft_putnbr(int nb)
//{
//	unsigned int	n;
//
//	if (nb < 0)
//	{
//		ft_putchar('-');
//		n = -nb;
//	}
//	else
//		n = nb;
//	if (n > 9)
//	{
//		ft_putnbr(n / 10);
//		n %= 10;
//	}
//	ft_putchar(n + '0');
//}

size_t	ft_putnbr(int value)
{
	size_t size;
	
	if (value < 10)
	{
		putchar(0x30 + value);
		return (1);
	}
	size = ft_putnbr(value / 10);
	putchar(0x30 + value % 10);
	return (1 + size);
}