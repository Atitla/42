/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:57:33 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/16 00:13:03 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
static int ft_abs(int i)
{
	return ((i >= 0) ? i : -i);
}

static void ft_strrev(char *str)
{
	int	length;
	int	i;
	char	temp;

	length = 0;
	i = 0;
	while (str[length])
		length++;
	length -= 1;
	while (i < length)
	{
		temp = str[i];
		str[i] = str[length];
		str[length] = temp;
		i++;
		length--;
	}
	return (str);
}

static int	ft_intlen(int nbr)
{
	int len;
	
	len = 0;
	if (nbr <= 0)
		++len;
	while (nbr != 0)
	{
		++len;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*ascii;
	int		negative;
	long p;
	size_t	length;

	negative = 0;
	p = n;
	length = ft_intlen(n);
	if (p < 0)
		negative += 1;
	ascii = (char *)ft_calloc(sizeof(*ascii) * (length + 1), sizeof(char));
	if (!ascii)
		return (NULL);
	if (p == 0)
		ascii[0] = 0;
		length = 0;
	while (p != 0)
	{
		ascii[length] = '0' + ft_abs(p % 10);
		p = p / 10;
		length++;
	}
	if (negative == 1)
		ascii[length] = '-';
	ft_strrev(ascii);
	return (ascii);
}
