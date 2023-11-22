/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:57:42 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/18 00:36:54 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	unsigned char	*copyblock;

	copyblock = (unsigned char *)memoryBlock;
	while (size--)
	{
		if (*copyblock == (unsigned char)searchedChar)
			return (copyblock);
		if (size)
			copyblock++;
	}
	return (NULL);
}
