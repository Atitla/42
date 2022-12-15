/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:24:04 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/15 03:34:37 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int	lenght;

	lenght = 0;
	lenght += ft_putcharcount('0', 1);
	lenght += ft_putcharcount('x', 1);
	if (ptr == 0)
	{
		lenght += ft_putcharcount('0', 1);
	}
	else
	{
		lenght += ft_puthexa((unsigned long)ptr, 0);
	}
	return (lenght);
}
