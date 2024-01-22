/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:14:20 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/22 14:48:10 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pathfinding(t_data *data)
{
	char	**temp_matrix;
	int		i;
	int		j;

	i = 0;
	temp_matrix = matrix_cpy_alloc(data);
	if (!temp_matrix)
		return (write(2, "Error\nmalloc failed\n", 21), \
				ft_free(data->map), exit(1), 1);
	fill_map(temp_matrix, (data->pos_x / STEP), (data->pos_y / STEP));
	while (temp_matrix[i] != NULL)
	{
		j = 0;
		while (temp_matrix[i][j] != '\0')
		{
			if (temp_matrix[i][j] == 'E' || temp_matrix[i][j] == 'C')
				return (ft_free(temp_matrix), ft_free(data->map), \
				write(2, "Error\nCollectible or Exit unreachable\n", 38), \
				exit(1), 0);
			j++;
		}
		i++;
	}
	ft_free(temp_matrix);
	return (0);
}

void	only_valid_characters(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map[i] != NULL )
	{
		j = -1;
		while (j < data->map_columns - 2)
		{
			j++;
			if (data->map[i][j] != '1' && data->map[i][j] != '0' \
			&& data->map[i][j] != 'E' && data->map[i][j] != 'C' \
			&& data->map[i][j] != 'P')
				return (ft_free(data->map), \
				write(2, "Error\nWrong character in map\n", 29), \
				exit(1));
		}
		i++;
	}
}

void	place_player(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (data->map[i] != NULL )
	{
		j = -1;
		while (j < data->map_columns - 2)
		{
			j++;
			if (data->map[i][j] == 'P')
				break ;
		}
		if (data->map[i][j] == 'P')
			break ;
		i++;
	}
	data->pos_y = i * STEP;
	data->pos_x = j * STEP;
	only_valid_characters(data);
	pathfinding(data);
}

int	check_required(int exit_count, int player, int collectibles, t_data *data)
{
	if (exit_count == 1 && player == 1 && collectibles >= 1)
		return (place_player(data), 0);
	else if (exit_count < 1 || exit_count > 1)
		return (write(2, "Error\nOne and only one exit\n", 28), \
				ft_free(data->map), exit(1), 1);
	else if (player < 1 || player > 1)
		return (write(2, "Error\nOne and only one player\n", 30), \
				ft_free(data->map), exit(1), 1);
	else if (collectibles < 1)
		return (write(2, "Error\nAt least one collectible\n", 31), \
				ft_free(data->map), exit(1), 1);
	return (write(2, "Error\nbizarre la\n", 18), \
				ft_free(data->map), exit(1), 1);
}

int	map_inside_valid(t_data *data)
{
	int	i;
	int	j;
	int	exit_count;
	int	player;
	int	collectible;

	i = 0;
	exit_count = 0;
	player = 0;
	collectible = 0;
	while (data->map[i] != NULL )
	{
		j = -1;
		while (++j < data->map_columns - 1)
		{
			if (data->map[i][j] == 'E')
				exit_count += 1;
			if (data->map[i][j] == 'P')
				player += 1;
			if (data->map[i][j] == 'C')
				collectible += 1;
		}
		i++;
	}
	return (check_required(exit_count, player, collectible, data));
}
