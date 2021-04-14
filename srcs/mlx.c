#include "minirt.h"

int             close_window(t_vars *vars)
{
    mlx_destroy_window(vars->mlx, vars->win);
    exit(0);
    return (0);
}

void           my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

int             key_hook(int keycode, t_vars *vars)
{
    // void    *vars;
    
    // printf("Hello from key_hook! %d\n", keycode);
    if (keycode == 53)
        close_window(vars);
    return (0);
}