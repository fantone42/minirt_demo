#include "minirt.h"

t_camera *new_camera(t_vector *origin, t_vector *direction, float fov)
{
    t_camera    *cam;

    cam = malloc(sizeof(t_camera));
    if (!cam)
        error_exit(-1);
    cam->origin = origin;
    cam->direction = direction;
    cam->fov = fov;
    return (cam); 
}
