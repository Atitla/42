/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:58:04 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/16 00:30:23 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int unsigned	i;

	i = 0;
	if (size == 0 || size == 1)
		return (ft_strlen(src));
	else
	{
		while (src[i])
		{	
			dest[i] = src[i];
			i++;
			if (i == size - 1)
			{
				dest[i] = '\0';
				return (ft_strlen(src));
			}
		}
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
