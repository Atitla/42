/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 00:24:04 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/22 13:22:41 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putptr(void *ptr)
{
	int	lenght;

	lenght = 0;
	if (ptr == 0)
		lenght += write(1, "(nil)", 5);
	else
	{
		lenght += ft_putcharcount('0', 1);
		lenght += ft_putcharcount('x', 1);
		lenght += ft_puthexa((unsigned long)ptr, 0);
	}
	return (lenght);
}
