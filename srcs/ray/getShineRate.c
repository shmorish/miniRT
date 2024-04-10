#include "miniRT.h"

#define DIFFUSE_REFLECTION 0.69f /* 拡散反射係数 */
#define SPECULAR_REFLECTION 0.5f /* 鏡面反射係数 */
#define AMBIENT_LIGHT_REFLECTION 1.0 /* 環境光反射係数 */
#define GLOSSINESS 100.0 /* 光沢度 */

// 制限をmin~maxまでの範囲にする
static double	constrain(double n, double min, double max)
{
	if (n > max)
		n = max;
	else if (n < min)
		n = min;
	return (n);
}


static int	colorMatrixWithLightReflectionAndAmbientLight(int color, int ambient_light_radiance, double light_diffuse_radiance, double light_specular_reflection_radiance)
{
	const double min = 0.0;
	const double max = 1.0;
	double constrain_rate;
	double	light;

	light = light_diffuse_radiance + color_to_fcolor(ambient_light_radiance) + light_specular_reflection_radiance;
	constrain_rate = constrain(light, min, max);
	return (color * constrain_rate);
}

static t_float_rgb	radianceColor(t_rgb color, t_rgb ambient_light_radiance, double light_diffuse_radiance, double light_specular_reflection_radiance)
{
	t_float_rgb	radiance;

	radiance.red = colorMatrixWithLightReflectionAndAmbientLight(color.red, ambient_light_radiance.red, light_diffuse_radiance, light_specular_reflection_radiance);
	radiance.green = colorMatrixWithLightReflectionAndAmbientLight(color.green, ambient_light_radiance.green, light_diffuse_radiance, light_specular_reflection_radiance);
	radiance.blue = colorMatrixWithLightReflectionAndAmbientLight(color.blue, ambient_light_radiance.blue, light_diffuse_radiance, light_specular_reflection_radiance);
	return (radiance);
}

// 直接光の拡散反射光の放射輝度の内積 [incidence_vec 入射ベクトル], [normal 法線ベクトル]
static double	_calc_light_specular_reflection_radiance_dot(t_vector ray, t_vector incidence_vec, t_vector normal)
{
	const t_vector	regular_reflection = subtraction(scale(normal, 2.0 * dot_product(normal, incidence_vec)), incidence_vec);
	const t_vector	rev_ray = normalize(scale(ray, -1.0));
	double				dot;

	dot = dot_product(rev_ray, regular_reflection);
	return (constrain(dot, 0.0, 1.0));
}

// 視線ベクトルの逆ベクトルと正反射ベクトルの内積
static double	_get_light_specular_reflection_dot(const t_vector ray, const double dot, const t_vector incidence_vec, const t_vector normal_vec)
{
	if (dot <= 0.0)
		return (0.0);
	return (_calc_light_specular_reflection_radiance_dot(ray, incidence_vec, normal_vec));
}

t_rgb	objs_get_rgb(t_object *node)
{
	if (node != NULL)
	{
		if (node->type == PLANE_TYPE)
			return integer_to_rgb(((t_plane *)node->object_data)->color);
		else if (node->type == SPHERE_TYPE)
			return integer_to_rgb(((t_sphere *)node->object_data)->color);
		else if (node->type == CYLINDER_TYPE)
			return integer_to_rgb(((t_cylinder *)node->object_data)->color);
	}
	ft_dprintf(STDERR_FILENO, "error occered file:[%s] line:[%d]\n", __FILE__, __LINE__);
	return (integer_to_rgb(0));
}

// rayとオブジェクトの交点位置
t_vector	rayObjCrossPos(t_vector camera_pos, double t, t_vector ray)
{
	return (addition(camera_pos, scale(ray, t)));
}

// 入射ベクトル
t_vector	get_incidence_vector(t_vector light_pos, t_vector intersection_pos)
{
	return (normalize(subtraction(light_pos, intersection_pos)));
}

// 法線ベクトル
t_vector	get_normal_vector(t_vector intersection_pos, t_object *node)
{
	if (node != NULL)
	{
		if (node->type == PLANE_TYPE)
			return (((t_plane *)node->object_data)->direction);
		else if (node->type == SPHERE_TYPE)
			return (normalize(subtraction(intersection_pos, getCoordinates(node->object_data, SPHERE_TYPE))));
		else if (node->type == CYLINDER_TYPE)
			return (get_normal_cylinder(intersection_pos, node));
	}
	ft_dprintf(STDERR_FILENO, "error occered file:[%s] line:[%d]\n", __FILE__, __LINE__);
	return ((t_vector){0, 0, 0});
}

double	get_incidence_dot(t_data *data, t_object *node, t_vector ray, double t)
{
	t_vector		intersection_pos;
	t_vector		incidence_vec;
	t_vector		normal;
	double			dot;

	intersection_pos = rayObjCrossPos(data->camera.coordinate, t, ray);
	incidence_vec = get_incidence_vector(data->light.position, intersection_pos);
	normal = get_normal_vector(intersection_pos, node);
	dot = dot_product(normal, incidence_vec);
	return (constrain(dot, 0.0, 1.0));
}

#define C_EPSILON 512.0
#define C_1_EPSILON (1 / C_EPSILON) 

double	shadow_res(t_data *data, t_vector shadow_ray, t_vector intersection_pos)
{
	t_object			*obj;
	const t_vector		shadow_ray_start = addition(intersection_pos, scale(shadow_ray, (C_1_EPSILON)));
	const double		t = objectCollotion(shadow_ray_start, data->object, shadow_ray, &obj) + (C_1_EPSILON);
	double				distance_to_light;

	distance_to_light = distance(data->light.position, intersection_pos) - (C_1_EPSILON);
	if (t < distance_to_light)
		return (t);
	return (-1.0);
}

// ambient_light_radiance : 環境光の反射光の放射輝度
// light_diffuse_radiance : 直接光の拡散反射光の放射輝度
// light_specular_reflection_radiance : 直接光の鏡面反射光の放射輝度
// 反射光の放射輝度
t_float_rgb	getShineRate(t_data *data, t_object *node, t_vector ray, const double t)
{
	const t_rgb	ambient_light_radiance = scale_rgb(integer_to_rgb(data->ambient_lightning.color), data->ambient_lightning.ratio);
	const double	dot = get_incidence_dot(data, node, ray, t);
	double	light_diffuse_radiance;
	double	light_specular_reflection_radiance;

	if (shadow_res(data, get_incidence_vector(data->light.position, rayObjCrossPos(data->camera.coordinate, t, ray)), rayObjCrossPos(data->camera.coordinate, t, ray)) >= 0.0)
	{
		light_diffuse_radiance = 0.0;
		light_specular_reflection_radiance = 0.0;
	}
	else
	{
		light_diffuse_radiance = data->light.ratio * dot;
		light_specular_reflection_radiance = pow(_get_light_specular_reflection_dot(ray, dot, get_incidence_vector(data->light.position, rayObjCrossPos(data->camera.coordinate, t, ray)), get_normal_vector(rayObjCrossPos(data->camera.coordinate, t, ray), node)), GLOSSINESS) * SPECULAR_REFLECTION * data->light.ratio;
	}
	return (radianceColor(objs_get_rgb(node), ambient_light_radiance, light_diffuse_radiance, light_specular_reflection_radiance));
}
