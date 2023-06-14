#include "mlx_linux/mlx.h"
#include <stdio.h>

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


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

int	my_mlx_pixel_put(int x, int y, t_data *data)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = 0x00FF0FF0;
	return (0);
}
int	mouse_pos(int x,int y, t_data *img)
{
	// printf("Hello from mouse_pos!\n %i \n", x);
	// printf("Hello from mouse_pos!\n %i \n", y);
	my_mlx_pixel_put(x, y, img);
	return (0);
}


int	main(void)
{
	t_vars	vars;
	t_data	img;
	t_data *data = &img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
			mlx_hook(vars.win, 6, 1L<<6, mouse_pos, &data);
			mlx_key_hook(vars.win, key_hook, &vars);
			mlx_mouse_hook(vars.win, mouse_hook, &vars);
			mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
		
		mlx_loop(vars.mlx);
}
