/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:37:57 by ecunha            #+#    #+#             */
/*   Updated: 2023/11/21 13:58:58 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == 10 || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int				i;
	long long int	number;
	int				j;

	i = ft_isspace(str);
	j = 1;
	number = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			j *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (number * j > LLONG_MAX)
			return (-1);
		else if (number * j < LLONG_MIN)
			return (0);
		else
			number = (number * 10) + (str[i] - 48);
		i++;
	}
	return (number * j);
}
