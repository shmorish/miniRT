#include "miniRT.h"

static int  transColor(int red, int green, int blue)
{
    return ((red << 16) | (green << 8) | blue);
}

static double	lengthFromObject(double current_t, double t, t_object *node, t_object **obj)
{
	if (t < 0.0)
		return (current_t);
	else if (current_t < 0.0 || fmin(current_t, t) == t)
	{
		*obj = node;
		return (t);
	}
	return (current_t);
}

t_vector getCoordinates(void *obj_data, t_object_type type)
{
	if (obj_data != NULL)
	{
		if (type == PLANE_TYPE)
			return ((t_plane *)obj_data)->coordinate;
		else if (type == SPHERE_TYPE)
			return ((t_sphere *)obj_data)->coordinate;
		else if (type == CYLINDER_TYPE)
			return ((t_cylinder *)obj_data)->coordinate;
	}
	ft_dprintf(STDERR_FILENO, "error occered file:[%s] line:[%d]\n", __FILE__, __LINE__);
	return ((t_vector){0, 0, 0});
}

double	objectCollotion(t_vector start_pos, t_object *object, t_vector ray, t_object **obj)
{
	double		t;
	t_object	*node;
	void		*obj_data;

	node = object;
	t = -1.0;
	while (node != NULL)
	{
		obj_data = node->object_data;
		if (node->type == PLANE_TYPE)
			t = lengthFromObject(t, hit_plane(ray, start_pos, getCoordinates(obj_data, PLANE_TYPE), ((t_plane *)obj_data)->direction), node, obj);
		else if (node->type == SPHERE_TYPE)
			t = lengthFromObject(t, hit_sphere(ray, start_pos, getCoordinates(obj_data, SPHERE_TYPE), ((t_sphere *)obj_data)->diameter / 2.0), node, obj);
		else if (node->type == CYLINDER_TYPE)
			t = lengthFromObject(t, hit_cylinder(ray, start_pos, (t_cylinder *)obj_data), node, obj);
		node = node->next;
	}
	return (t);
}

void    put_pixel(t_data *data, t_vector camera, int x, int y)
{
    t_object        *object;
	t_float_rgb     shine;
	const t_vector	coordinate = data->camera.coordinate;
	const double	t = objectCollotion(coordinate, data->object, camera, &object);

	if (t >= 0.0)
	{
		shine = getShineRate(data, object, camera, t);
		mlxPixel(data->mlx, x, y, transColor(shine.red, shine.green, shine.blue));
	}
	else
		mlxPixel(data->mlx, x, y, data->ambient_lightning.color);
}