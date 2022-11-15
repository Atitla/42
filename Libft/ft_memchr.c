/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:57:42 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/15 22:57:51 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void * memchr( const void * memoryBlock, int searchedChar, size_t size )
{
	unsigned char	*copyBlock;

	copyBlock = (unsigned char *)memoryBlock;
	while (size--)
	{
		if (*copyBlock == searchedChar)
			return (copyBlock);
		if (size)
			copyBlock++;
	}
	return (NULL);
}