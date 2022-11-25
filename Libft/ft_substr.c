/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 22:57:22 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/18 00:25:59 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if ()
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return("\0");
	if (len > ft_strlen(s))
		substr = (char *)malloc(sizeof(char) * ((ft_strlen(s) - start) + 1));
	else if (len + start > ft_strlen(s))
		substr = (char *)malloc(sizeof(char) * len);
	else
		substr = (char *)malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
