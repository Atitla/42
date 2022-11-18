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

int	is_a_separator(char c, char *charset)
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

int	range_to_sep(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_a_separator(str[i], charset))
		i++;
	return (i);
}

char *ft_strtrim(char const *s1, char const *set)
{
	char *str;
	char *dest;

	str = s1;
	while (is_a_separator(*s1, set))
		str++;
	dest = malloc(sizeof(char) * range_to_sep(str, (char *)set));
	ft_strlcpy(dest, str, range_to_sep(str, (char *)set));
	return (dest);
}
