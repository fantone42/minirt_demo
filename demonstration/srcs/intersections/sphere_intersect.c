/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersect.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantone <fantone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 15:21:28 by fantone           #+#    #+#             */
/*   Updated: 2021/04/07 18:09:47 by fantone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int     sphere_intersect(t_camera *cam,t_vector *ray, t_sphere *sphere)
{
	float		b;
	float		c;
	float		discr;
	float		dist_1; //ray intersect 1 time sphere
	float		dist_2; //ray intersect 2 time
	t_vector	*cam_sphere;
	
	dist_1 = 0;
	dist_2 = 0;
	cam_sphere = vector_subtract(cam->origin, sphere->center);
	b = 2 * (vec_dot_product(cam_sphere, ray));
	c = vec_dot_product(cam_sphere, cam_sphere) - (sphere->radius * sphere->radius);
	discr = (b * b) - (4 * c);
	free(cam_sphere);
	if (discr < 0)
		return (0);
	dist_1 = (b * (-1) - sqrt(discr))/2;
	// dist_2 = (b * (-1) + sqrt(discr))/2;
	if (dist_1 > 0)
		return (1);
	return (0);
}
