/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:56:47 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/18 00:35:41 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp( const void *pointer1, const void *pointer2, size_t size )
{
	size_t				i;
	const unsigned char	*str1;
	const unsigned char	*str2;

	if (pointer1 == pointer2 || size == 0)
		return (0);
	str1 = (const unsigned char *)pointer1;
	str2 = (const unsigned char *)pointer2;
	i = 0;
	while (size)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
		size--;
	}
	return (0);
}
