#include "minirt.h"



int main(void)
{
    // int x = -1;
    // int y = -1;
    t_vars 			vars;
    t_data  		img;
    t_vector        *sphere_center = new_vector(3, 2, -32);
    t_sphere        *sphere = new_sphere(sphere_center, 12/2);
	t_vector *a = new_vector(10, 20, 10);
	t_vector *b = new_vector(10, 10, 20);
	t_vector *c = new_vector(20, 10, 10);
	t_triangle		*triangle = new_triangle(a, b,  c);
    t_vector        *cam_origin = new_vector(0, 0, 0);
    t_vector        *cam_direction = new_vector(0, 0, -1);
    t_camera        *cam = new_camera(cam_origin, cam_direction, 50);
    t_scene         *scene = new_scene(cam, sphere, triangle);
    
	scene->height = 600;
    scene->width = 800;
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, scene->width, scene->height, "SPHERE");
	img.img = mlx_new_image(vars.mlx, scene->width, scene->height);
    img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	ray_tracing(&img, scene);
	mlx_key_hook(vars.win, key_hook, &vars);
    mlx_hook(vars.win, 17, 1L<<17, close_window, &vars);
    mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
    //free_scene(scene);
    mlx_loop(vars.mlx);
    return (0);
}
