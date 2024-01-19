/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:10:01 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/19 11:12:31 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *str)
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

char	**matrix_cpy_alloc(t_data *data)
{
	char	**temp_matrix;
	int		i;
	int		j;

	i = 0;
	temp_matrix = (char **)malloc(sizeof(char *) * (data->map_rows + 1));
	while (i < data->map_rows - 1)
	{
		j = -1;
		temp_matrix[i] = (char *)malloc(sizeof(char) * (data->map_columns + 1));
		while (++j < data->map_columns - 1)
			temp_matrix[i][j] = data->map[i][j];
		temp_matrix[i][j] = '\0';
		i++;
	}
	temp_matrix[i] = NULL;
	return (temp_matrix);
}

void	fill_map(char **temp_matrix, int x, int y)
{
	if (temp_matrix[y][x] == '1' || temp_matrix[y][x] == 'X')
		return ;
	temp_matrix[y][x] = 'X';
	fill_map(temp_matrix, x + 1, y);
	fill_map(temp_matrix, x - 1, y);
	fill_map(temp_matrix, x, y + 1);
	fill_map(temp_matrix, x, y - 1);
}
