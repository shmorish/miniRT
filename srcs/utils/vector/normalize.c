#include "miniRT.h"

t_vector	normalize(t_vector v)
{
	const double	mag = magnitude(v);
	const t_vector	mag_v = {mag, mag, mag};

	return (division(v, mag_v));
}