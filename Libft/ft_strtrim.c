/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 05:40:00 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/18 05:53:52 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_a_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *str;
	char *dest;
	int end;

	str = (char *)s1;
	if (!str)
		return(NULL);
	while (is_a_separator(*str, (char *)set))
		str++;
	end = ft_strlen(str);
	if (end == 0)
		return("\0");
	while (is_a_separator(str[end - 1], (char *)set))
		end--;
	dest = malloc(sizeof(char) * (end + 1));
	if (!dest)
		return (NULL);
	ft_strlcpy(dest, str, (end + 1));
	return (dest);
}