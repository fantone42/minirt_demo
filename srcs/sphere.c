/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantone <fantone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:57:06 by fantone           #+#    #+#             */
/*   Updated: 2021/04/07 16:58:20 by fantone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_sphere *new_sphere(t_vector *center, float radius)
{
    t_sphere    *sphere;

    sphere = malloc(sizeof(t_sphere));
    if (!sphere)
        error_exit(-1);
    sphere->center = center;
    sphere->radius = radius;
    return(sphere);   
}