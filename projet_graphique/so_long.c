/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 16:30:40 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/19 14:05:04 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	write(1, "Movements count = ", 19);
	ft_putnbr(data->count);
	write(1, "\n", 1);
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
		if (vars->map[(vars->pos_y / STEP) - 1][(vars->pos_x / STEP)] != '1')
			return (fmovements(1, vars), 0);
	if (keycode == 115 || keycode == 65364)
		if (vars->map[(vars->pos_y / STEP) + 1][(vars->pos_x / STEP)] != '1')
			return (fmovements(2, vars), 0);
	if (keycode == 97 || keycode == 65361)
		if (vars->map[(vars->pos_y / STEP)][(vars->pos_x / STEP) - 1] != '1')
			return (fmovements(3, vars), 0);
	if (keycode == 100 || keycode == 65363)
		if (vars->map[(vars->pos_y / STEP)][(vars->pos_x / STEP) + 1] != '1')
			return (fmovements(4, vars), 0);
	return (1);
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
