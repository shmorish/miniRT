/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shine_rate2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:43:41 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/11 00:44:03 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// rayとオブジェクトの交点位置
t_vector	ray_obj_cross_pos(t_vector camera_pos,
						double t,
						t_vector ray)
{
	return (addition(camera_pos, scale(ray, t)));
}

// 入射ベクトル
t_vector	get_incidence_vector(t_vector light_pos,
								t_vector intersection_pos)
{
	return (normalize(subtraction(light_pos, intersection_pos)));
}

// 法線ベクトル
t_vector	get_normal_vector(t_vector intersection_pos,
							t_object *node)
{
	if (node != NULL)
	{
		if (node->type == PLANE_TYPE)
			return (((t_plane *)node->object_data)->direction);
		else if (node->type == SPHERE_TYPE)
			return (normalize(subtraction(intersection_pos, \
			get_coordinates(node->object_data, SPHERE_TYPE))));
		else if (node->type == CYLINDER_TYPE)
			return (get_normal_cylinder(intersection_pos, node));
	}
	ft_dprintf(STDERR_FILENO, "error occered file:[%s] line:[%d]\n", \
			__FILE__, __LINE__);
	return ((t_vector){0, 0, 0});
}

double	get_incidence_dot(t_data *data,
						t_object *node,
						t_vector ray,
						double t)
{
	t_vector		intersection_pos;
	t_vector		incidence_vec;
	t_vector		normal;
	double			dot;

	intersection_pos = ray_obj_cross_pos(data->camera.coordinate, t, ray);
	incidence_vec = get_incidence_vector(data->light.position, \
		intersection_pos);
	normal = get_normal_vector(intersection_pos, node);
	dot = dot_product(normal, incidence_vec);
	return (constrain(dot, 0.0, 1.0));
}

double	shadow_res(t_data *data,
				t_vector shadow_ray,
				t_vector intersection_pos)
{
	t_object			*obj;
	const t_vector		shadow_ray_start = addition(intersection_pos, \
			scale(shadow_ray, (C_1_EPSILON)));
	const double		t = object_collotion(shadow_ray_start, data->object, \
			shadow_ray, &obj) + (C_1_EPSILON);
	double				distance_to_light;

	distance_to_light = distance(data->light.position, \
			intersection_pos) - (C_1_EPSILON);
	if (t < distance_to_light)
		return (t);
	return (-1.0);
}
