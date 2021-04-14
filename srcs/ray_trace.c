#include "minirt.h"

void ray_tracing(t_data *data, t_scene *scene)
{
    int     	mlx_x = 0;
    int     	mlx_y = 0; //for mlx_pixel_put
    float   	x_angle;
    float   	y_angle;
    int         color;
	float		y_ray;
	float		x_ray;
    t_vector    *ray;
	t_vplane	*vplane;
	

	vplane = get_view_plane(scene->width, scene->height, scene->cams->fov);
	y_angle = (scene->height / 2);
	mlx_y = 0;
	while(y_angle > (scene->height/2) *(-1))
	{
		y_ray = y_angle * vplane->y_pixel;
		x_angle = scene->width/2 * (-1);
		mlx_x = 0;
		while(x_angle <= scene->width/2)
		{
			x_ray = x_angle * vplane->x_pixel;
			ray = new_vector(x_ray, y_ray, -1);
			normalize_vec(ray);
			//if (sphere_intersect(scene->cams, ray, scene->sphere))
			//	color = create_trgb(0, 0, 100, 255);
			if (triangle_intersect(scene->cams, scene->triangle))
				color = create_trgb(0, 255, 100, 255);
			else
				color = 0;
			my_mlx_pixel_put(data, mlx_x, mlx_y, color);
			free(ray);
			x_angle++;
			mlx_x++;
		}
		y_angle--;
		mlx_y++;
	}
}

t_vplane *get_view_plane(float width, float height, float fov)
{
	t_vplane	*vplane;
	float		aspect_ratio;

	vplane = malloc(sizeof(t_vplane));
	if (!vplane)
		error_exit(-1);
	aspect_ratio = width / height;
	vplane->width = 2 * tan(fov / 2 * (M_PI / 180));
	vplane->height = vplane->width / aspect_ratio;
	vplane->x_pixel = vplane->width / width;
	vplane->y_pixel = vplane->height / height;
	return (vplane);
}
