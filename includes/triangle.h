/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fantone <fantone@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 19:28:08 by fantone           #+#    #+#             */
/*   Updated: 2021/04/14 21:44:08 by fantone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRIANGLE_H
# define TRIANGLE_H

typedef struct	s_triangle
{
	t_vector *a;
	t_vector *b;
	t_vector *c;

}				t_triangle;

t_triangle  *new_triangle(t_vector *a, t_vector *b, t_vector *c);
t_vector    *triangle_normal(t_triangle *triangle);

#endif