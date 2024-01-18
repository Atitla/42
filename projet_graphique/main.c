/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:30:40 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/18 22:40:27 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "N.h"

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

int	pathfinding(t_data *data)
{
	char	**temp_matrix;
	int		i;
	int		j;

	i = 0;
	temp_matrix = matrix_cpy_alloc(data);
	fill_map(temp_matrix, (data->pos_x / STEP), (data->pos_y / STEP));
	while (temp_matrix[i] != NULL)
	{
		j = 0;
		while (temp_matrix[i][j] != '\0')
		{
			if (temp_matrix[i][j] == 'E' || temp_matrix[i][j] == 'C')
				return (ft_free(temp_matrix), ft_free(data->map), exit(1), \
				write(2, "Error\nCollectible or Exit unreachable\n", 39), 0);
			j++;
		}
		i++;
	}
	ft_free(temp_matrix);
	return (0);
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
	pathfinding(data);
}

int	check_required(int exit_count, int player, int collectibles, t_data *data)
{
	int	i;
	int	j;

	if (exit_count == 1 && player == 1 && collectibles >= 1)
		return (place_player(data), 0);
	else if (exit_count < 1 || exit_count > 1)
		return (write(2, "Error\nOne and only one exit\n", 29), \
				ft_free(data->map), exit(1), 1);
	else if (player < 1 || player > 1)
		return (write(2, "Error\nOne and only one player\n", 31), \
				ft_free(data->map), exit(1), 1);
	else if (collectibles < 1)
		return (write(2, "Error\nAt least one collectible\n", 32), \
				ft_free(data->map), exit(1), 1);
	return (write(2, "Error\nbizarre la\n", 18), \
				ft_free(data->map), exit(1), 1);
	i = 0;
	while (data->map[i] != NULL )
	{
		j = -1;
		while (++j < data->map_columns - 1)
		{

		}
		i++;
	}
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

int	check_1(char *str, t_data *data)
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
	check_1(str, data);
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

int	close_mlx(int keycode, t_data *vars)
{
	(void)keycode;
	ft_free(vars->map);
	mlx_destroy_image(vars->ptr.mlx, vars->textures[0]);
	mlx_destroy_image(vars->ptr.mlx, vars->textures[1]);
	mlx_destroy_image(vars->ptr.mlx, vars->textures[2]);
	mlx_destroy_image(vars->ptr.mlx, vars->textures[3]);
	mlx_destroy_image(vars->ptr.mlx, vars->textures[4]);
	mlx_destroy_window(vars->ptr.mlx, vars->ptr.win);
	mlx_destroy_display(vars->ptr.mlx);
	free((*vars).ptr.mlx);
	exit(0);
}

int	coin_left(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_rows - 1)
	{
		j = 0;
		while (j < data->map_columns - 1)
		{
			if (data->map[i][j] == 'C')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	print_texture(t_data *img, int i, int j, int text_index)
{
	mlx_put_image_to_window(img->ptr.mlx, img->ptr.win, \
				img->textures[text_index], \
				(j * img->text_size[(text_index * 2)]), \
				(i * img->text_size[(text_index * 2) + 1]));
}

void	render_with_map(t_data *img, int i, int j)
{
	if ((j * STEP) == img->pos_x && ((i * STEP) == img->pos_y))
	{
		mlx_put_image_to_window(img->ptr.mlx, img->ptr.win, \
					img->textures[0], img->pos_x, img->pos_y);
	}
	else if (img->map[i][j] == '0')
		print_texture(img, i, j, 1);
	else if (img->map[i][j] == '1')
		print_texture(img, i, j, 2);
	else if (img->map[i][j] == 'C')
		print_texture(img, i, j, 3);
	else if (img->map[i][j] == 'E' && coin_left(img) == 0)
		print_texture(img, i, j, 4);
	else if (img->map[i][j] == 'E' && coin_left(img) == 1)
		print_texture(img, i, j, 1);
	else if (img->map[i][j] == 'P' && img->count != 0)
		print_texture(img, i, j, 1);
}

int	render_next_frame(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->map_rows - 1)
	{
		j = -1;
		while (++j < img->map_columns - 1)
			render_with_map(img, i, j);
		i++;
	}
	return (img->count);
}

int	fmovements(int flag, t_data *data)
{
	if (flag == 1)
		data->pos_y -= STEP;
	else if (flag == 2)
		data->pos_y += STEP;
	else if (flag == 3)
		data->pos_x -= STEP;
	else if (flag == 4)
		data->pos_x += STEP;
	data->count += 1;
	printf("Movements count = %i\n", data->count);
	if (data->map[(data->pos_y / STEP)][(data->pos_x / STEP)] == 'C')
	{
		data->map[(data->pos_y / STEP)][(data->pos_x / STEP)] = '0';
		data->coins_earn++;
	}
	if (data->map[(data->pos_y / STEP)][(data->pos_x / STEP)] == 'E' \
		&& coin_left(data) == 0)
		close_mlx(0, data);
	render_next_frame(data);
	return (0);
}

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == 65307)
		close_mlx(keycode, vars);
	if (keycode == 119 || keycode == 65362)
	{
		if (vars->map[(vars->pos_y / STEP) - 1][(vars->pos_x / STEP)] != '1')
			return (fmovements(1, vars), 0);
	}
	if (keycode == 115 || keycode == 65364)
	{
		if (vars->map[(vars->pos_y / STEP) + 1][(vars->pos_x / STEP)] != '1')
			return (fmovements(2, vars), 0);
	}
	if (keycode == 97 || keycode == 65361)
	{
		if (vars->map[(vars->pos_y / STEP)][(vars->pos_x / STEP) - 1] != '1')
			return (fmovements(3, vars), 0);
	}
	if (keycode == 100 || keycode == 65363)
	{
		if (vars->map[(vars->pos_y / STEP)][(vars->pos_x / STEP) + 1] != '1')
			return (fmovements(4, vars), 0);
	}
	return (1);
}

void	import_textures(t_data *data)
{
	data->textures[0] = mlx_xpm_file_to_image(data->ptr.mlx, PLAYER, \
						&data->text_size[0], &data->text_size[1]);
	if (data->textures[0] == NULL)
		return (mlx_destroy_display(data->ptr.mlx), ft_free(data->map), \
				exit(1));
	data->textures[1] = mlx_xpm_file_to_image(data->ptr.mlx, FLOOR, \
						&data->text_size[2], &data->text_size[3]);
	if (data->textures[1] == NULL)
		return (mlx_destroy_display(data->ptr.mlx), ft_free(data->map), \
				exit(1));
	data->textures[2] = mlx_xpm_file_to_image(data->ptr.mlx, WALL, \
						&data->text_size[4], &data->text_size[5]);
	if (data->textures[2] == NULL)
		return (mlx_destroy_display(data->ptr.mlx), ft_free(data->map), \
				exit(1));
	data->textures[3] = mlx_xpm_file_to_image(data->ptr.mlx, COIN, \
						&data->text_size[6], &data->text_size[7]);
	if (data->textures[3] == NULL)
		return (mlx_destroy_display(data->ptr.mlx), ft_free(data->map), \
				exit(1));
	data->textures[4] = mlx_xpm_file_to_image(data->ptr.mlx, EXITS, \
						&data->text_size[8], &data->text_size[9]);
	if (data->textures[4] == NULL)
		return (mlx_destroy_display(data->ptr.mlx), ft_free(data->map), \
				exit(1));
}

int	main(int argc, char **argv)
{
	t_data	img;

	if (argc == 2)
		is_map_dot_ber(argv[1], &img);
	else
		return (1);
	img.ptr.mlx = mlx_init();
	if (img.ptr.mlx == NULL)
		return (1);
	import_textures(&img);
	img.ptr.win = mlx_new_window(img.ptr.mlx, \
	((img.map_columns - 1) * img.text_size[4]), \
	((img.map_rows - 1) * img.text_size[5]), "So_long");
	render_next_frame(&img);
	mlx_hook(img.ptr.win, 2, 1L << 0, key_hook, &img);
	mlx_loop(img.ptr.mlx);
	return (0);
}
