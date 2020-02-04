#include "mini.h"

float vect_prod(t_cord a, t_cord b)
{
    return(a.x*b.x + a.y*b.y + a.z*b.z);
}

t_cord vect_scalar_prod(t_cord a, float x)
{
    t_cord b;

    b.x = x*a.x;
    b.y = x*a.y;
    b.z = x*a.z;
    return(b);
}

t_cord vect_add(t_cord a, t_cord b)
{
    t_cord c;

    c.x = a.x + b.x;
    c.y = a.y + b.y;
    c.z = a.z + b.z;
    return(c);
}

t_cord vect_normalize(t_cord a)
{
    return(vect_scalar_prod(a, 1 / sqrt(vect_prod(a, a))));
}

void print_vect(t_cord a)
{
    printf("x: %f\n", a.x);
    printf("y: %f\n", a.y);
    printf("z: %f\n", a.z);
}