/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:32:12 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/27 19:54:50 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	count = 0;
	if (str == NULL)
		count += write(1, "(null)", 6);
	else
	{
		i = -1;
		while (str[++i])
			count += ft_putcharcount(str[i], 1);
	}
	return (count);
}
