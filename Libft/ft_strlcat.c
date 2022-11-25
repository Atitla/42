/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 00:33:47 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/17 00:19:47 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;
	size_t	len_src;

	if ((!dst || !src) && n == 0)
		return(0);
	len_src = ft_strlen(src);
	len_dest = ft_strlen(dst);
	j = len_dest;
	i = 0;
	if (len_dest < n - 1 && n > 0)
	{
		while (src[i] && len_dest + i < n - 1)
		{
			dst[j] = src[i];
			j++;
			i++;
		}
		dst[j] = 0;
	}
	if (len_dest >= n)
		len_dest = n;
	return (len_dest + len_src);
}
