#include "mlx_linux/mlx.h"
#include <stdio.h>
#define ARGB(a,r,g,b) ((a << 24) | (r << 16) | (g << 8) | b)
#define WIGHT 1920
#define HEIGHT 1080

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_vars;

inline int	my_mlx_pixel_put(int x, int y, int color, t_vars *data)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	return (0);
}

int fractal(int x, int y)
{

}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, WIGHT, HEIGHT, "Hello world!");
	vars.img = mlx_new_image(vars.mlx, WIGHT, HEIGHT);
	vars.addr = mlx_get_data_addr(vars.img, &vars.bits_per_pixel, &vars.line_length,
								&vars.endian);

	int i = 0;
	while (i < 1920 * 1080)
	{
		my_mlx_pixel_put(i % WIGHT, i / WIGHT, ARGB(0, 255, 0, 0), &vars);
		if (i > 1)
			mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
		i++;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img, 0, 0);
		mlx_loop(vars.mlx);

}
