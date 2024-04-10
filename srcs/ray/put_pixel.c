/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pixel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:14:37 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/11 00:37:16 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static double	length_from_object(double current_t,
							double t,
							t_object *node,
							t_object **obj)
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

t_vector	get_coordinates(void *obj_data,
						t_object_type type)
{
	if (obj_data != NULL)
	{
		if (type == PLANE_TYPE)
			return (((t_plane *)obj_data)->coordinate);
		else if (type == SPHERE_TYPE)
			return (((t_sphere *)obj_data)->coordinate);
		else if (type == CYLINDER_TYPE)
			return (((t_cylinder *)obj_data)->coordinate);
	}
	ft_dprintf(STDERR_FILENO, "error occered file:[%s] line:[%d]\n", \
			__FILE__, __LINE__);
	return ((t_vector){0, 0, 0});
}

double	object_collotion(t_vector start_pos,
					t_object *object,
					t_vector ray,
					t_object **obj)
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
			t = length_from_object(t, hit_plane(ray, start_pos, \
				get_coordinates(obj_data, PLANE_TYPE), \
				((t_plane *)obj_data)->direction), node, obj);
		else if (node->type == SPHERE_TYPE)
			t = length_from_object(t, hit_sphere(ray, start_pos, \
				get_coordinates(obj_data, SPHERE_TYPE), \
				((t_sphere *)obj_data)->diameter / 2.0), node, obj);
		else if (node->type == CYLINDER_TYPE)
			t = length_from_object(t, hit_cylinder(ray, start_pos, \
				(t_cylinder *)obj_data), node, obj);
		node = node->next;
	}
	return (t);
}

void	put_pixel(t_data *data,
			t_vector camera,
			int x,
			int y)
{
	t_object		*object;
	t_float_rgb		shine;
	const t_vector	coordinate = data->camera.coordinate;
	const double	t = object_collotion(coordinate, data->object, \
		camera, &object);

	if (t >= 0.0)
	{
		shine = get_shine_rate(data, object, camera, t);
		my_mlx_pixcel_put(data->mlx, x, y, trans_color(shine.red, shine.green, \
			shine.blue));
	}
	else
		my_mlx_pixcel_put(data->mlx, x, y, data->ambient_lightning.color);
}
