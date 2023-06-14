#include "mlx_linux/mlx.h"
#include <stdio.h>
#define ARGB(a,r,g,b) ((a << 24) | (r << 16) | (g << 8) | b)

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

int	close(int keycode,t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(data, x + i, y + j, color);
			j++;
		}
		i++;
	}
}
void	draw_triangle(t_data *data, int x, int y, int size, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			my_mlx_pixel_put(data,(x + i),(y + j), color);
			printf("x: %d, y: %d\n", x + i, y + j);
			j++;
		}
		i++;
	}
}

void	draw_circle(t_data *data, int x0, int y0, int size, int color)
{
	int	x;
	int	y;

	x = 0;
	while (x <= x0 + size)
	{
		y = 0;
		while (y <= y0 + size)
		{
			if ((x - x0) * (x - x0) + (y - y0) * (y - y0) <= size * size)
				my_mlx_pixel_put(data, x, y, color);
			y++;
		}
		x++;
	}
	
}

int	main(void)
{
	t_vars	vars;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int color = 0;
	int red = 255;
	int green = 0;
	int blue = 0;
	int step = 1;
	int x = 0;
	int size = 50;
	int y = 0;
	int i = 0;

	vars.mlx = mlx = mlx_init();
	vars.win = mlx_win = mlx_new_window(mlx, 1920, 1080, "test");
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	while (x < 1920 + size)
	{
		x = i + (size * 2);
		y = 0;
		green = 0;
		red = 255;
		blue = 0;
		while (green < 255 || red > 0 || blue < 255 || green > 0 || red < 255 || blue > 0)
		{
			if (green < 255)
				green += step;
			else if (red > 0)
				red -= step;
			else if (blue < 255)
				blue += step;
			else if (green > 0)
				green -= step;
			else if (red < 255)
				red += step;
			else
				blue -= step;
			color = ARGB(255, red, green, blue);
			y += 1;
			if (y == 1080 - size || x == 1920 - size)
				break;
			draw_circle(&img,x,y,size,color);
			mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		}
		i += (size * 2);
	}
	mlx_hook(vars.win, 2, 1L<<0, close(Escape, &vars), &vars);
	mlx_loop(vars.mlx);
}
