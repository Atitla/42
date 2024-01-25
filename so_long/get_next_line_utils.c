/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:54:23 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/22 16:20:45 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strchr(const char *string, int searchedChar )
{
	char	*str;

	str = (char *)string;
	while (*str != searchedChar && *str != 0)
		str++;
	if (*str == searchedChar)
		return (str);
	else
		return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)s;
	i = 0;
	while (i < n)
	{
		str[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t elementCount, size_t elementSize)
{
	char	*strfnl;

	strfnl = malloc(elementSize * elementCount);
	if (!strfnl)
		return (NULL);
	ft_bzero(strfnl, elementSize * elementCount);
	return (strfnl);
}

size_t	ft_strlen_st(const char *tstrfnltring)
{
	int	i;

	i = 0;
	while (tstrfnltring[i])
		i++;
	return (i);
}
