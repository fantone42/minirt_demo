#ifndef VIEW_PLANE_H
# define VIEW_PLANE_H

typedef struct s_vplane
{
    float	width;
	float	height;
	float	x_pixel;
	float	y_pixel;
}              t_vplane;

t_vplane	*get_view_plane(float width, float height, float fov);
int			sphere_intersect(t_camera *cam,t_vector *ray, t_sphere *sphere);
void		ray_tracing(void   *mlx, void  *window, t_scene *scene);

#endif