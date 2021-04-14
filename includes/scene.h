#ifndef SCENE_H
# define SCENE_H

typedef struct  s_scene
{
    t_camera    *cams;
    t_sphere    *sphere;
    t_triangle  *triangle;
    float       width;
    float       height;
}               t_scene;

t_scene *new_scene(t_camera    *cam, t_sphere    *sphere, t_triangle    *triangle);

#endif