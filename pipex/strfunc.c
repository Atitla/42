/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strfunc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/01 14:48:14 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/04 20:14:42 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str1;
	char	*str2;
	char	*dest;
	int		i;
	int		j;

	str1 = (char *)s1;
	str2 = (char *)s2;
	if (!s1)
		return ((char *) s2);
	else if (!s2)
		return ((char *) s1);
	dest = malloc ((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	i = -1;
	while (str1[++i])
		dest[i] = str1[i];
	j = -1;
	while (str2[++j])
		dest[i + j] = str2[j];
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, int n)
{
	int	i;

	if (s1 == NULL || s2 == NULL)
	{
		if (s1 == NULL && s2 == NULL)
			return (0);
		else if (s1 == NULL)
			return (-1);
		else
			return (1);
	}
	i = 0;
	while ((s1[i] || s2[i]) && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *src)
{
	int		i;
	int		len;
	char	*str;

	len = 0;
	while (src[len])
		len++;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = src[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	close_fds(t_pipex files)
{
	if (files.fd1 != -1)
		close(files.fd1);
	if (files.fd2 != -1)
		close(files.fd2);
}
