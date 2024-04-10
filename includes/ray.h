/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:56:57 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/11 00:54:22 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "struct.h"
# include "miniRT.h"

# define DIFFUSE_REFLECTION 0.69f /* 拡散反射係数 */
# define SPECULAR_REFLECTION 0.5f /* 鏡面反射係数 */
# define AMBIENT_LIGHT_REFLECTION 1.0 /* 環境光反射係数 */
# define GLOSSINESS 100.0 /* 光沢度 */
# define C_EPSILON 512.0
// 1 / 512
# define C_1_EPSILON 0.001953125

t_vector	get_camera_ray(t_data *data,
				int x,
				int y);

void		put_pixel(t_data *data,
				t_vector camera_ray,
				int x,
				int y);

t_float_rgb	get_shine_rate(t_data *data,
				t_object *node,
				t_vector ray,
				const double t);

double		hit_plane(t_vector ray,
				t_vector camera_pos,
				t_vector obj_pos,
				t_vector obj_dir);

double		hit_cylinder(t_vector ray,
				t_vector start_pos,
				t_cylinder *cylinder);

t_vector	get_coordinates(void *obj_data,
				t_object_type type);

t_vector	get_normal_cylinder(t_vector intersection_pos,
				t_object *node);

double		object_collotion(t_vector start_pos,
				t_object *head,
				t_vector ray,
				t_object **obj);

double		hit_sphere(t_vector ray,
				t_vector camera_pos,
				t_vector obj_pos,
				double radius);

t_vector	ray_obj_cross_pos(t_vector camera_pos,
				double t,
				t_vector ray);

t_vector	get_incidence_vector(t_vector light_pos,
				t_vector intersection_pos);

t_vector	get_normal_vector(t_vector intersection_pos,
				t_object *node);

double		get_incidence_dot(t_data *data,
				t_object *node,
				t_vector ray,
				double t);

double		shadow_res(t_data *data,
				t_vector shadow_ray,
				t_vector intersection_pos);

double		constrain(double n,
				double min,
				double max);

int			apply_color_matrix_with_light(int color,
				int ambient_light_radiance,
				double light_diffuse_radiance,
				double light_specular_reflection_radiance);

t_float_rgb	radiance_color(t_rgb color,
				t_rgb ambient_light_radiance,
				double light_diffuse_radiance,
				double light_specular_reflection_radiance);

double		_calc_light_specular_reflection_radiance_dot(t_vector ray,
				t_vector incidence_vec,
				t_vector normal);

#endif
