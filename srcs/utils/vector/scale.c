#include "miniRT.h"

t_vector	scale(t_vector a, double scale)
{
    t_vector	result;

    result.x = a.x * scale;
    result.y = a.y * scale;
    result.z = a.z * scale;
    return (result);
}