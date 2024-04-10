#include "miniRT.h"

static double	caluculateRayLength(double a, double b, double c)
{
	const double	t1 = (-b + sqrt(pow(b, 2.0) - (4.0 * a * c))) / (2.0 * a);
	const double	t2 = (-b - sqrt(pow(b, 2.0) - (4.0 * a * c))) / (2.0 * a);

	if (t1 > 0.0 && t2 > 0.0)
		return (fmin(t1, t2));
	else
		return (fmax(t1, t2));
}

// 球体とレイの交差判定をおこなう
double	hit_sphere(t_vector ray, t_vector camera_pos, t_vector obj_pos, double radius)
{
	const double	a = magnitude_squared(ray);
	const double	b = 2.0 * dot_product(subtraction(camera_pos, obj_pos), ray);
	const double	c = magnitude_squared(subtraction(camera_pos, obj_pos)) - pow(radius, 2.0);
	const double	d = pow(b, 2.0) - (4.0 * a * c);

	if (d == 0.0)
		return (-(b) / (2.0 * a));
	else if (d < 0)
		return (-1.0);
	return (caluculateRayLength(a, b, c));
}
