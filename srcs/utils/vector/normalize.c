#include "miniRT.h"

t_vector	normalize(t_vector v)
{
	double          mag;
	t_vector		result;

    mag = magnitude(v);
	result.x = v.x / mag;
	result.y = v.y / mag;
	result.z = v.z / mag;
	return (result);
}