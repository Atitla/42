/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:57:04 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/15 21:57:09 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
void * calloc( size_t elementCount, size_t elementSize ){
	int size;
	int i;
	void *tab;

	i = 0;
	size = elementCount * elementSize;
	tab = (void *)malloc(size);
	if (!tab)
		return (NULL);
	ft_bzero(tab, size);
	return(tab);
	
}