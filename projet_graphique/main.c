/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:30:40 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/13 20:40:50 by ecunha           ###   ########.fr       */
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

char *get_first_row(char *str, int *fd, t_data *data)
{
	char	*first_row;
	int		i;

	(*fd) = open(str, O_RDONLY);
	if ((*fd) == -1)
		return (perror("So_long :"), exit(1), NULL);
	first_row = get_next_line((*fd));
	if (first_row == NULL)
		return (write(1, "So_long : file is empty\n", 26), exit(1), \
				close((*fd)), NULL);
	data->map_columns = ft_strlen(str);
	data->map_rows = 1;
	return (first_row);
}

int	map_parser(char *str, t_data *data)
{
	char	*row;
	char	*matrix;
	char	*temp_matrix;
	int		i;
	int		fd;

	row = get_first_row(str, &fd, data);
	matrix = ft_strdup("");
	if (matrix == NULL)
		return (write(1, "So_long : malloc failed\n", 25), \
				close(fd), exit(1), 1);
	while (row)
	{
		temp_matrix = ft_strjoin(matrix, row);
		if (ft_strlen(row) != data->map_columns)
		has_same_column(row, matrix, data);
		matrix = temp_matrix;
		row = get_next_line(fd);
	}
	close(fd);

}

void	is_map_dot_ber(char *str, t_data *data)
{
	int	i;

	i = ft_strlen(str);
	if (i < 5)
	{
		write(2, "So_long : Not a actual file\n", 27);
		exit(1);
	}
	else if (str[i - 4] == '.' && str[i - 3] == 'b' \
		&& str[i -2] == 'e' && str[i - 1] == 'r')
		map_parser(str, data);
	else
	{
		write(2, "So_long : Not a .ber file\n", 28);
		exit(1);
	}
}

int	close_mlx(int keycode, t_data *vars)
{
	(void)keycode;
	//mlx_destroy_image(vars->ptr.mlx, vars->img);
	mlx_destroy_window(vars->ptr.mlx, vars->ptr.win);
	mlx_destroy_display(vars->ptr.mlx);
	free((*vars).ptr.mlx);
	exit(1);
	return(0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_t(int trgb)
{
	return ((trgb >> 24) & 0xFF);
}

int	get_r(int trgb)
{
	return ((trgb >> 16) & 0xFF);
}

int	get_g(int trgb)
{
	return ((trgb >> 8) & 0xFF);
}

int	get_b(int trgb)
{
	return (trgb & 0xFF);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int h, int l)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < l)
		{
			my_mlx_pixel_put(data, (i + data->pos_x), (j + data->pos_y), 0x00FF0000);
			j++;
		}
		i++;
	}
}

void	draw_(t_data *data, int h, int l, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < l)
			my_mlx_pixel_put(data, i, j++, color);
		i++;
	}
}


void	draw_background(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIDTH)
	{
		j = 0;
		while (j < HEIGHT)
			my_mlx_pixel_put(img, i, j++, img->color);
		i++;
	}
}

int	render_next_frame(t_data *img)
{
	int i = 0;
	int j = 0;
	// draw_square(img, 50, 50);
	while (i < (WIDTH / img->textures_size[2]) + 1)
	{
		j = 0;
		while (j < (HEIGHT / img->textures_size[3] + 1))
		{
			mlx_put_image_to_window(img->ptr.mlx, img->ptr.win, img->textures[1], (i * img->textures_size[2]), (j * img->textures_size[3]));
			j++;
		}
		i++;
	}

	mlx_put_image_to_window(img->ptr.mlx, img->ptr.win, img->textures[0], img->pos_x, img->pos_y);
	return (0);
}

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == 65307)
		close_mlx(keycode, vars);
	if (keycode == 119 || keycode == 65362)
	{
		if(vars->pos_y > STEP)
			return(vars->pos_y -= STEP, vars->count += 1, printf("Movements count = %i\n", vars->count), render_next_frame(vars), 0);
	}
	if (keycode == 115 || keycode == 65364)
	{
		if(vars->pos_y < HEIGHT - STEP - 50)
			return(vars->pos_y += STEP, vars->count += 1, printf("Movements count = %i\n", vars->count), render_next_frame(vars), 0);
	}
	if (keycode == 97 || keycode == 65361)
	{
		if(vars->pos_x > STEP)
			return(vars->pos_x -= STEP, vars->count += 1, printf("Movements count = %i\n", vars->count), render_next_frame(vars), 0);
	}
	if (keycode == 100 || keycode == 65363)
	{
		if(vars->pos_x < WIDTH - STEP)
			return(vars->pos_x += STEP, vars->count += 1, printf("Movements count = %i\n", vars->count), render_next_frame(vars), 0);
	}
	//printf("Movements count = %i\n", vars->count);
	//if (keycode != 65307 && keycode != 119 && keycode != 115 && keycode != 97 && keycode != 100)
	//	printf("keycode : %i\n", keycode);
	return (1);
}

int	main(void)
{
	t_data	img;
	img.color = create_trgb(0, 0, 0, 255);
	img.pos_x = (WIDTH / 2);
	img.pos_y = (HEIGHT / 2);
	img.count = 0;

	img.ptr.mlx = mlx_init();
	if (img.ptr.mlx == NULL)
		return(1);
	img.ptr.win = mlx_new_window(img.ptr.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(img.ptr.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img.textures[0] = mlx_xpm_file_to_image(img.ptr.mlx,"orange_bizarre_64x64.xpm", &img.textures_size[0], &img.textures_size[1]);
	if(img.textures[0] == NULL)
		return(close_mlx(0, &img), 1);
	img.textures[1] = mlx_xpm_file_to_image(img.ptr.mlx,"grass.xpm", &img.textures_size[2], &img.textures_size[3]);
	if(img.textures[0] == NULL)
		return(close_mlx(0, &img), 1);
	draw_background(&img);
	render_next_frame(&img);
	mlx_hook(img.ptr.win, 2, 1L<<0, key_hook, &img);
	mlx_loop(img.ptr.mlx);
	return (0);
}
