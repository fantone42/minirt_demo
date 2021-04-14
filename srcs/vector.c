/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantone <fantone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 20:03:26 by fantone           #+#    #+#             */
/*   Updated: 2021/04/14 22:09:29 by fantone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vector    *new_vector(float x, float y, float z)
{
    t_vector    *vec;

    vec = malloc(sizeof(t_vector));
    if (!vec)
        error_exit(-1);
    vec->x = x;
    vec->y = y;
    vec->z = z;
    return (vec);
}

t_vector    *vec_subtract(t_vector *vec1, t_vector *vec2)
{
    t_vector    *result;

    result = new_vector(vec1->x - vec2->x, vec1->y - vec2->y, vec1->z - vec2->z);
    return (result);
}

float   vec_length(t_vector *vec)
{
    float   result;

    result = sqrt((vec->x * vec->x) + (vec->y * vec->y) + (vec->z * vec->z));
    return (result);
}

void    normalize_vec(t_vector *vec)
{
    float length;

    length = vec_length(vec);
    vec->x /= length;
    vec->y /= length;
    vec->z /= length; 
}

float       vec_dot_product(t_vector *vec1, t_vector *vec2)
{
    float   result;

    result = ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
    return (result);
}

t_vector    *vec_add(t_vector *vec1, t_vector *vec2)
{
    t_vector    *result;

    result = new_vector(vec1->x + vec2->x, vec1->y + vec2->y,
            vec1->z + vec2->z);
    return (result);
}

t_vector    *vec_mult(t_vector *vec, double d)
{
    t_vector    *result;

    result = new_vector(d * vec->x, d * vec->y, d * vec->z);
    return (result);
}

t_vector    *cross_prod(t_vector *vec1, t_vector *vec2)
{
    t_vector    *result;

    result = new_vector(0, 0, 0);
    result->x = vec1->y * vec2->z - vec1->z * vec2->y;
    result->y = vec1->z * vec2->x - vec1->x * vec2->z;
    result->z = vec1->x * vec2->y - vec1->y * vec2->x;
    return (result);
}
