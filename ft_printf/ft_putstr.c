/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 12:32:12 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/14 21:49:36 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;
	int	count;

	i = -1;
	count = 0;
	while (str[++i])
		count += ft_putcharcount(str[i]);
	return (count);
}
