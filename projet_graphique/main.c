#include "N.h"


int	close_mlx(int keycode, t_data *vars)
{
	(void)keycode;
	mlx_destroy_image(vars->ptr.mlx, vars->img);
	mlx_destroy_window(vars->ptr.mlx, vars->ptr.win);
	//mlx_destroy_display(vars->ptr.mlx);
	free((*vars).ptr.mlx);
	exit(0);
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
	// draw_square(img, 50, 50);
	mlx_put_image_to_window(img->ptr.mlx, img->ptr.win, img->img, 0, 0);
	while (i < (WIDTH / img->textures_size[2]) + 1)
	{
		mlx_put_image_to_window(img->ptr.mlx, img->ptr.win, img->textures[1], (i * img->textures_size[2]), 0);
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

	img.ptr.mlx = mlx_init();
	img.ptr.win = mlx_new_window(img.ptr.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(img.ptr.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	img.textures[0] = mlx_xpm_file_to_image(img.ptr.mlx,"gandalf.xpm", &img.textures_size[0], &img.textures_size[1]);
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
