/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shine_rate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:51:01 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/11 00:54:08 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// 視線ベクトルの逆ベクトルと正反射ベクトルの内積
static double	_get_light_specular_reflection_dot(const t_vector ray,
												const double dot,
												const t_vector incidence_vec,
												const t_vector normal_vec)
{
	if (dot <= 0.0)
		return (0.0);
	return (_calc_light_specular_reflection_radiance_dot(ray, \
				incidence_vec, normal_vec));
}

t_rgb	objs_get_rgb(t_object *node)
{
	if (node != NULL)
	{
		if (node->type == PLANE_TYPE)
			return (integer_to_rgb(((t_plane *)node->object_data)->color));
		else if (node->type == SPHERE_TYPE)
			return (integer_to_rgb(((t_sphere *)node->object_data)->color));
		else if (node->type == CYLINDER_TYPE)
			return (integer_to_rgb(((t_cylinder *)node->object_data)->color));
	}
	ft_dprintf(STDERR_FILENO, "error occered file:[%s] line:[%d]\n", \
			__FILE__, __LINE__);
	return (integer_to_rgb(0));
}

static bool	detect_shadow(t_data *data, double t, t_vector ray)
{
	return (shadow_res(data, get_incidence_vector(data->light.position, \
		ray_obj_cross_pos(data->camera.coordinate, t, ray)), \
		ray_obj_cross_pos(data->camera.coordinate, t, ray)) >= 0.0);
}

// ambient_light_radiance : 環境光の反射光の放射輝度
// light_diffuse_radiance : 直接光の拡散反射光の放射輝度
// light_specular_reflection_radiance : 直接光の鏡面反射光の放射輝度
// 反射光の放射輝度
t_float_rgb	get_shine_rate(t_data *data,
						t_object *node,
						t_vector ray,
						const double t)
{
	const t_rgb		ambient_light_radiance = scale_rgb(integer_to_rgb(\
		data->ambient_lightning.color), data->ambient_lightning.ratio);
	const double	dot = get_incidence_dot(data, node, ray, t);
	double			light_diffuse_radiance;
	double			light_specular_reflection_radiance;

	if (detect_shadow(data, t, ray))
	{
		light_diffuse_radiance = 0.0;
		light_specular_reflection_radiance = 0.0;
	}
	else
	{
		light_diffuse_radiance = data->light.ratio * dot;
		light_specular_reflection_radiance = pow(\
			_get_light_specular_reflection_dot(ray, dot, \
			get_incidence_vector(data->light.position, \
			ray_obj_cross_pos(data->camera.coordinate, t, ray)), \
			get_normal_vector(ray_obj_cross_pos(data->camera.coordinate, \
			t, ray), node)), GLOSSINESS) * \
			SPECULAR_REFLECTION * data->light.ratio;
	}
	return (radiance_color(objs_get_rgb(node), \
		ambient_light_radiance, light_diffuse_radiance, \
		light_specular_reflection_radiance));
}
