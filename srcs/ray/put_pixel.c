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

t_vector	obtainObjectCoordinates(t_object *node)
{
	if (node->type == PLANE_TYPE)
		return (((t_plane *)node->object_data)->coordinate);
	else if (node->type == SPHERE_TYPE)
		return (((t_sphere *)node->object_data)->coordinate);
	else if (node->type == CYLINDER_TYPE)
		return (((t_cylinder *)node->object_data)->coordinate);
	return ((t_vector){0, 0, 0});
}

double	objectCollotion(t_vector start_pos, t_object *head, t_vector ray, t_object **obj)
{
	double		t;
	t_object	*node;

	node = head->next;
	t = -1.0;
	while (node != NULL)
	{
		if (node->type == PLANE_TYPE)
			t = lengthFromObject(t, hit_plane(ray, start_pos, obtainObjectCoordinates(node), ((t_plane *)node->object_data)->direction), node, obj);
		else if (node->type == SPHERE_TYPE)
			t = lengthFromObject(t, hit_sphere(ray, start_pos, obtainObjectCoordinates(node), ((t_sphere *)node->object_data)->diameter / 2), node, obj);
		else if (node->type == CYLINDER_TYPE)
			t = lengthFromObject(t, hit_cylinder(ray, start_pos, (t_cylinder *)node->object_data), node, obj);
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