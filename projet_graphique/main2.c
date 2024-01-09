#include "N.h"


int	close(int keycode, t_data *vars)
{
	(void)keycode;
	mlx_destroy_image(vars->ptr.mlx, vars->img);
	//mlx_destroy_display(vars->ptr.mlx);
	mlx_destroy_window(vars->ptr.mlx, vars->ptr.win);
	exit (0);
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
			my_mlx_pixel_put(data, i, j++, 0x00FF0000);
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

int	key_hook(int keycode, t_data *vars)
{
	if (keycode == 65307)
		close(keycode, vars);
	return (1);
}

void	draw_background(t_data *img)
{
	int	i;
	int	j;

	i = 0;
	while (i < LENGHT)
	{
		j = 0;
		while (j < HEIGHT)
			my_mlx_pixel_put(img, i, j++, img->color);
		i++;
	}
}

int	render_next_frame(t_data *img)
{
	draw_square(img, 10, 10);
	mlx_put_image_to_window(img->ptr.mlx, img->ptr.win, img->img, 0, 0);

	return (0);
}

int	main(void)
{
	t_data	img;

	int	longeur;
	int	hauteur;
	img.color = create_trgb(0, 0, 0, 255);


	img.ptr.mlx = mlx_init();
	if (img.ptr.mlx == NULL)
		return(1);

	img.ptr.mlx = mlx_init();
	img.ptr.win = mlx_new_window(img.ptr.mlx, hauteur, longeur, "Hello world!");
	//img.img = mlx_new_image(img.ptr.mlx, LENGHT, HEIGHT);
	img.img = mlx_xpm_file_to_image(img.ptr.mlx,"./dog.xml", &hauteur, &longeur);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	//draw_background(&img);
	mlx_put_image_to_window(img.ptr.mlx, img.ptr.win, img.img, 0, 0);
	//mlx_loop_hook(img.ptr.mlx, render_next_frame, &img);
	mlx_key_hook(img.ptr.win, key_hook, &img);
	mlx_loop(img.ptr.mlx);
	return (0);
}
