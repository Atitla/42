/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:57:50 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/16 00:19:47 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memset(void *b, int c, size_t len){
	size_t i;

	i = 0;
	if (!b)
		return(0);
	while (i < len)
	{
		*(unsigned char *)(b + i) = c;
		i++;
	}
	return(b);
}
