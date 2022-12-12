/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 01:21:23 by ecunha            #+#    #+#             */
/*   Updated: 2022/12/12 22:35:44 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static char	**ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
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
	while (str[i] && charset != str[i])
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
		return (1);
	while (str[i])
	{
		while (str[i] && charset == str[i])
			i++;
		if (str[i])
			word++;
		while (str[i] && charset != str[i])
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
		while (*str && c == str[0])
			str++;
		if (*str)
		{
			split[i] = ft_strndup(str, range_to_sep(str, c));
			if (!split[i])
				return (ft_free(split));
			i++;
		}
		while (*str && c != str[0])
			str++;
	}
	split[i] = NULL;
	return (split);
}
