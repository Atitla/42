/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 21:57:59 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/15 21:58:01 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *src)
{
	char	*dest;

	dest = malloc((ft_strlen(src) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}