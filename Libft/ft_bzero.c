/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:56:58 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/16 00:20:00 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n){
	
	size_t i;

	i = 0;
	if (!s)
		return(0);
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
	return(s);
}
