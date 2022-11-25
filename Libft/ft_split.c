/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:21:23 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/18 00:18:29 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static char **ft_free(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return(NULL);
}
static int	is_a_separator(const char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

char	*ft_strndup(const char *src, int n)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i] && i < n)
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	while (j < n)
	{
		dest[j] = src[j];
		j++;
	}
	dest[n] = '\0';
	return (dest);
}

static int	range_to_sep(const char *str, char charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_a_separator(str[i], charset))
		i++;
	return (i);
}

static int	count_word(const char *str, char charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	if (!charset)
		return (0);
	while (str[i])
	{
		while (str[i] && is_a_separator(str[i], charset))
			i++;
		if (str[i])
			word++;
		while (str[i] && !is_a_separator(str[i], charset))
			i++;
	}
	return (word);
}

char	**ft_split(const char *str, char c)
{
	int		i;
	char	**split;

	i = 0;
	if (!str)
		return (NULL);
	split = malloc(sizeof(char *) * (count_word(str, c) + 1));
	if (!split)
		return (NULL);
	while (*str)
	{
		while (*str && is_a_separator(*str, c))
			str++;
		if (*str)
		{
			split[i] = ft_strndup(str, range_to_sep(str, c));
			if (!split[i])
				return (ft_free(split));
			i++;
		}
		while (*str && !is_a_separator(*str, c))
			str++;
	}
	split[i] = 0;
	return (split);
}
