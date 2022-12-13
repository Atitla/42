/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 12:10:15 by ecunha            #+#    #+#             */
/*   Updated: 2022/11/17 03:07:20 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

char	*ft_strndup(char *src, int n)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	j = 0;
	while (src[i] && i < n)
		i++;
	dest = malloc(sizeof(char) * i + 1);
	while (src[j] && j < n)
	{
		dest[j] = src[j];
		j++;
	}
	dest[n] = '\0';
	return (dest);
}

int	range_to_sep(char *str, char *charset)
{
	int	i;

	i = 0;
	while (str[i] && !is_a_separator(str[i], charset))
		i++;
	return (i);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
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

char	**ft_split(char *str, char *charset)
{
	int		i;
	char	**split;

	i = 0;
	split = malloc(sizeof(char *) * count_word(str, charset) + 1);
	if (!split)
		return (NULL);
	split[count_word(str, charset)] = NULL;
	while (*str)
	{
		while (*str && is_a_separator(*str, charset))
			str++;
		if (*str)
			split[i] = ft_strndup(str, range_to_sep(str, charset));
		str += range_to_sep(str, charset);
		i++;
	}
	return (split);
}

#include <stdio.h>
int main(int argc, char **argv)
{
    (void)argc;
    char **res = ft_split(argv[1], argv[2]);
    int i = 0;
    while (res[i])
    {
        printf("t[%d] = %s\n", i, res[i]);
        i++;
    }
    printf("%s",res[i]);
}