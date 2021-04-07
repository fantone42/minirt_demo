#ifndef CAMERA_H
# define CAMERA_H

typedef struct  s_camera
{
    t_vector    *origin;
    t_vector    *direction;
    float       fov;
}               t_camera;

t_camera *new_camera(t_vector *origin, t_vector *direction, float fov);

#endif