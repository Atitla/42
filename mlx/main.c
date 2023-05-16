#include "mlx.h"

int main()
{
    void *mlx_ptr;
    void *win_ptr;

    mlx_ptr = mlx_init();
    win_ptr = mlx_new_window(mlx_ptr, 500, 500, "Ma fenêtre");

    mlx_pixel_put(mlx_ptr, win_ptr, 250, 250, 0xFF0000);

    mlx_loop(mlx_ptr);

    return 0;
}
