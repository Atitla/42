/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecunha <ecunha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 11:17:09 by ecunha            #+#    #+#             */
/*   Updated: 2024/01/22 14:28:02 by ecunha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_mlx(t_data *vars)
{
	mlx_destroy_image(vars->ptr.mlx, vars->textures[0]);
	mlx_destroy_image(vars->ptr.mlx, vars->textures[1]);
	mlx_destroy_image(vars->ptr.mlx, vars->textures[2]);
	mlx_destroy_image(vars->ptr.mlx, vars->textures[3]);
	mlx_destroy_image(vars->ptr.mlx, vars->textures[4]);
	mlx_destroy_window(vars->ptr.mlx, vars->ptr.win);
	mlx_destroy_display(vars->ptr.mlx);
	free((*vars).ptr.mlx);
	ft_free(vars->map);
	exit(0);
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
