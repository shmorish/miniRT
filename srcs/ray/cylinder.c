#include "miniRT.h"

typedef struct s_cylinder_ray
{
	t_vector	ray_t1;
	t_vector	ray_t2;
}t_cylinder_ray;

static bool	check_cylinder_cross(double dot, double height, double t)
{
	if (0 <= dot && dot <= height && t > 0)
		return (true);
	else
		return (false);
}
// 交点までの距離
static double	caluculateRayLength(t_cylinder *cylinder, t_cylinder_ray ray_cylinder, t_tmp t)
{
	if (check_cylinder_cross(dot_product(ray_cylinder.ray_t1, cylinder->direction), cylinder->height, t.t1))
		t.t = t.t1;
	else if (check_cylinder_cross(dot_product(ray_cylinder.ray_t2, cylinder->direction), cylinder->height, t.t2))
		t.t = t.t2;
	else
		t.t = -1.0;
	cylinder->t = t;
	return (t.t);
}

static t_cylinder_ray	get_cylinder_ray(t_vector start_pos, t_cylinder *cylinder, t_tmp t, t_vector camera_ray)
{
	t_cylinder_ray	ray;

	ray.ray_t1 = subtraction(addition(start_pos, scale(camera_ray, t.t1)), cylinder->coordinate);
	ray.ray_t2 = subtraction(addition(start_pos, scale(camera_ray, t.t2)), cylinder->coordinate);
	return (ray);
}


double	hit_cylinder(t_vector ray, t_vector start_pos, t_cylinder *cylinder)
{
	t_tmp		t;
	t_cylinder_ray	ray_cylinder;

	t.a = magnitude_squared(cross_product(ray, cylinder->direction));
	if (t.a == 0.0)
		return (-1.0);
	t.b = 2.0 * (dot_product(cross_product(ray, cylinder->direction), cross_product(subtraction(start_pos, cylinder->coordinate), cylinder->direction)));
	t.c = magnitude_squared(cross_product(subtraction(start_pos, cylinder->coordinate), cylinder->direction)) - pow(cylinder->diameter / 2.0, 2.0);
	t.d = pow(t.b, 2.0) - (t.a * t.c * 4.0);
	t.t1 = (-(t.b) - sqrt(t.d)) / (t.a * 2.0);
	t.t2 = (-(t.b) + sqrt(t.d)) / (t.a * 2.0);
	ray_cylinder = get_cylinder_ray(start_pos, cylinder, t, ray);
	return (caluculateRayLength(cylinder, ray_cylinder, t));
}

t_vector	get_normal_cylinder(t_vector intersection_pos, t_object *node)
{
	t_vector	intersection_sub_coordinate;
	t_vector	dot_direction;
	t_cylinder	*cylinder;

	cylinder = ((t_cylinder *)node->object_data);
	intersection_sub_coordinate = subtraction(intersection_pos, cylinder->coordinate);
	dot_direction = scale(cylinder->direction, dot_product(intersection_sub_coordinate, cylinder->direction));
	if (cylinder->t.t == cylinder->t.t1)
		return (scale(subtraction(intersection_sub_coordinate, dot_direction), 1.0 / distance(intersection_sub_coordinate, dot_direction)));
	else
		return (scale(subtraction(dot_direction, intersection_sub_coordinate), 1.0 / distance(dot_direction, intersection_sub_coordinate)));
}
