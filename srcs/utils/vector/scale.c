#include "miniRT.h"

t_vector	scale(t_vector a, double scale)
{
    t_vector	result;

    result.x = a.x * scale;
    result.y = a.y * scale;
    result.z = a.z * scale;
    return (result);
}

t_rgb    scale_rgb(t_rgb a, double scale)
{
    t_rgb	result;

    result.red = a.red * scale;
    result.green = a.green * scale;
    result.blue = a.blue * scale;
    return (result);
}