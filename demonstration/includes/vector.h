#ifndef VECTOR_H
# define VECTOR_H



typedef struct	s_vector
{
    float	x;
    float	y;
    float	z;
}				t_vector;

t_vector    *new_vector(float x, float y, float z);
t_vector    *vector_subtract(t_vector *vec1, t_vector *vec2);
float       vec_length(t_vector *vec);
void        normalize_vec(t_vector *vec);
float       vec_dot_product(t_vector *vec1, t_vector *vec2);


#endif