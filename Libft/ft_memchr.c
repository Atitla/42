/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:57:42 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/16 05:38:22 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memchr( const void * memoryBlock, int searchedChar, size_t size )
{
	unsigned char	*copyBlock;

	copyBlock = (unsigned char *)memoryBlock;
	while (size--)
	{
		if (*copyBlock == (unsigned char)searchedChar)
			return (copyBlock);
		if (size)
			copyBlock++;
	}
	return (NULL);
}