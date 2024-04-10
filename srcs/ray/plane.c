#include "miniRT.h"

// 平面とrayの交差判定
double	hit_plane(t_vector ray, t_vector camera_pos, t_vector obj_pos, t_vector obj_dir)
{
	double	t;

	t = -1.0 * (dot_product(subtraction(camera_pos, obj_pos), obj_dir)) / dot_product(ray, obj_dir);
	if (isnan(t))
		t = -1.0;
	return (t);
}