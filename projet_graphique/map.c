/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:13:12 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/19 11:25:07 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_first_line(char *str, t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		if (data->map[i][0] != '1')
			return (write(2, "Error\nmap not close\n", 21), \
					ft_free(data->map), free(str), exit(1), 1);
		if (data->map[i][data->map_columns - 2] != '1')
			return (write(2, "Error\nmap not close\n", 21), \
					ft_free(data->map), free(str), exit(1), 1);
		i++;
	}
	return (0);
}

int	map_border_valid(char *str, t_data *data)
{
	int	i;

	data->map = ft_split(str, '\n');
	if (!data->map)
		return (write(2, "Error\nmalloc failed\n", 21), free(str), exit(1), 1);
	check_first_line(str, data);
	i = 0;
	while (data->map[0][i] != '\0')
	{
		if (data->map[0][i] != '1')
			return (write(2, "Error\nmap not close\n", 21), \
					ft_free(data->map), free(str), exit(1), 1);
		if (data->map[data->map_rows -2][i] != '1')
			return (write(2, "Error\nmap not close\n", 21), \
					ft_free(data->map), free(str), exit(1), 1);
		i++;
	}
	return (free(str), map_inside_valid(data));
}

char	*get_first_row(char *str, int *fd, t_data *data)
{
	char	*first_row;

	(*fd) = open(str, O_RDONLY);
	if ((*fd) == -1)
		return (perror("Error\n"), exit(1), NULL);
	first_row = get_next_line((*fd));
	if (first_row == NULL)
		return (write(2, "Error\nfile is empty\n", 21), exit(1), \
				close((*fd)), NULL);
	data->map_columns = ft_strlen(first_row);
	data->map_rows = 1;
	return (first_row);
}

int	map_parser(char *str, t_data *data)
{
	char	*row;
	char	*matrix;
	char	*temp_matrix;
	int		fd;

	row = get_first_row(str, &fd, data);
	matrix = ft_strdup("");
	if (matrix == NULL)
		return (write(2, "Error\nmalloc failed\n", 21), \
				close(fd), free(row), free(matrix), exit(1), 1);
	while (row)
	{
		temp_matrix = ft_strjoin(matrix, row);
		if (ft_strlen(row) != data->map_columns)
			return (write(2, "Error\nColumns don't match\n", 27), \
			free(row), free(matrix), free(temp_matrix), close(fd), exit(1), 1);
		data->map_rows++;
		free(row);
		free(matrix);
		matrix = temp_matrix;
		row = get_next_line(fd);
	}
	close(fd);
	return (free(row), map_border_valid(matrix, data), 0);
}

void	is_map_dot_ber(char *str, t_data *data)
{
	int	i;

	data->count = 0;
	data->coins_earn = 0;
	data->textures[0] = 0;
	data->textures[1] = 0;
	data->textures[2] = 0;
	data->textures[3] = 0;
	data->textures[4] = 0;
	i = ft_strlen(str);
	if (i < 5)
	{
		write(2, "Error\nNot a actual file\n", 25);
		exit(1);
	}
	else if (str[i - 4] == '.' && str[i - 3] == 'b' \
		&& str[i -2] == 'e' && str[i - 1] == 'r')
		map_parser(str, data);
	else
	{
		write(2, "Error\nNot a .ber file\n", 23);
		exit(1);
	}
}
