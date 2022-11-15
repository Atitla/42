/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:57:33 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/15 21:57:35 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
char *ft_itoa(int n){
	char	*ascii;
	int		negative;
	size_t	length;

	negative = 0;
	if (n < 0)
		negative += 1;
	ascii = ft_calloc();
	if (!ascii)
		return(NULL);
	if (n = 0)
		ascii[0] = 0;
		length = 0;
	while (n != 0)
	{
		ascii[length] = '0' + ft_abs(n % 10);
		n = n / 10;
		length++;
	}
	if (negative == 1)
		ascii[length] = '-';
	ft_strrev(ascii);
	return(ascii);
	
	
	
	
}
