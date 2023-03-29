#include "get_next_line.h"

char	*ft_strjoin(char const *str1, char const *str2)
{
	int		size;
	char	*strfnl;
	int		i;
	int		j;

	i = 0;
	size = ft_strlen(str1) + ft_strlen(str2);
	strfnl = malloc(sizeof(char) * (size + 1));
	if (!strfnl || !str1 || !str2)
		return (NULL);
	while (str1[i])
	{
		strfnl[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		strfnl[i] = str2[j];
		i++;
		j++;
	}
	strfnl[size] = 0;
	return (strfnl);
}

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

size_t	ft_strlen(const char *tstrfnltring)
{
	int	i;

	i = 0;
	while (tstrfnltring[i])
		i++;
	return (i);
}
