/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantone <fantone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:24:25 by fantone           #+#    #+#             */
/*   Updated: 2021/04/14 22:09:14 by fantone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

t_triangle *new_triangle(t_vector *a, t_vector *b, t_vector *c)
{
    t_triangle    *triangle;

    triangle = malloc(sizeof(triangle));
    if (!triangle)
        error_exit(-1);
    triangle->a = a;
    triangle->b = b;
    triangle->c = c;
    return(triangle);   
}

t_vector *triangle_normal(t_triangle *triangle)
{
    t_vector    *a;
    t_vector    *b;
    t_vector    *normal;

    a = vec_subtract(triangle->b, triangle->a);
    b = vec_subtract(triangle->c, triangle->a);
    normal = cross_prod(a, b);
    normalize_vec(normal);
    return (normal);
}

int			check_edges(t_triangle *triangle, t_vector *p, t_vector *n)
{
	t_vector	*c;
	t_vector	*edge;
	t_vector	*vp;

	edge = vec_subtract(triangle->b, triangle->a);
	vp = vec_subtract(p, triangle->a);
	c = cross_prod(edge, vp);
	if (vec_dot_product(n, c) < 0)
		return (0);
	edge = vec_subtract(triangle->c, triangle->b);
	vp = vec_subtract(p, triangle->b);
	c = cross_prod(edge, vp);
	if (vec_dot_product(n, c) < 0)
		return (0);
	edge = vec_subtract(triangle->a, triangle->c);
	vp = vec_subtract(p, triangle->c);
	c = cross_prod(edge, vp);
	if (vec_dot_product(n, c) < 0)
		return (0);
	return (1);
}

int			triangle_intersect(t_camera *cams, t_triangle *triangle)
{
	t_vector	*a;
	t_vector	*b;
	t_vector	*n;
	double	    angle;
	t_vector	*p;
    double      t;

	a = vec_subtract(triangle->b, triangle->a);
	b = vec_subtract(triangle->c, triangle->a);
	n = cross_prod(a, b);
	normalize_vec(n);
	angle = vec_dot_product(n, cams->direction);
	if (fabs(angle) < 1e-6)
		return (0);
	t  = (vec_dot_product(n, vec_subtract(triangle->a, cams->origin)) / angle);
	if (t < 0)
		return (0);
	p = vec_add(cams->origin, vec_mult(cams->direction, t));
	return (check_edges(triangle, p, n));
}