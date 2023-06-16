#include "mlx_linux/mlx.h"
#include <stdio.h>
#define ARGB(a,r,g,b) ((a << 24) | (r << 16) | (g << 8) | b)

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;

int	key_hook(int keycode, t_vars *vars)
{
	printf("Hello from key_hook!\n %i \n", keycode);
	return (0);
}

int	mouse_hook(int keycode, t_vars *vars)
{
	printf("Hello from mouse_hook!\n %i \n", keycode);
	return (0);
}


int	my_mlx_pixel_put(int x, int y, int color, t_vars *data)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return (0);
}

void	draw_square(int x, int y, int size, int color, t_vars *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(x + i, y + j, color, data);
			j++;
		}
		i++;
	}
}

void	draw_circle(int x0, int y0, int size, int color, t_vars *data)
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
				my_mlx_pixel_put(x, y, color, data);
			y++;
		}
		x++;
	}

}


int	mouse_pos(int x,int y, t_vars *vars)
{
	static	int	green = 0;
	static	int	red = 255;
	static	int	blue = 0;
	int step = 1;
	int color = 0;
	if (green == 255 && red == 0 && blue == 255)
	{
		green = 0;
		blue = 0;
		red = 255;
	}

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
	draw_circle(x, y, 10, color, vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
	return (0);
}


int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	vars.img = mlx_new_image(vars.mlx, 1920, 1080);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);
			mlx_hook(vars.win, 6, 1L<<6, mouse_pos, &vars);
			mlx_key_hook(vars.win, key_hook, &vars);
			mlx_mouse_hook(vars.win, mouse_hook, &vars);
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);

		mlx_loop(vars.mlx);
}
