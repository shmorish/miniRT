/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_shine_rate3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 00:47:34 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/11 00:48:29 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

// 制限をmin~maxまでの範囲にする
double	constrain(double n,
				double min,
				double max)
{
	if (n > max)
		n = max;
	else if (n < min)
		n = min;
	return (n);
}

int	apply_color_matrix_with_light(int color,
								int ambient_light_radiance,
								double light_diffuse_radiance,
								double light_specular_reflection_radiance)
{
	const double	min = 0.0;
	const double	max = 1.0;
	double			constrain_rate;
	double			light;

	light = light_diffuse_radiance + color_to_fcolor(ambient_light_radiance) \
			+ light_specular_reflection_radiance;
	constrain_rate = constrain(light, min, max);
	return (color * constrain_rate);
}

t_float_rgb	radiance_color(t_rgb color,
						t_rgb ambient_light_radiance,
						double light_diffuse_radiance,
						double light_specular_reflection_radiance)
{
	t_float_rgb	radiance;

	radiance.red = apply_color_matrix_with_light(color.red, \
			ambient_light_radiance.red, light_diffuse_radiance, \
			light_specular_reflection_radiance);
	radiance.green = apply_color_matrix_with_light(color.green, \
			ambient_light_radiance.green, light_diffuse_radiance, \
			light_specular_reflection_radiance);
	radiance.blue = apply_color_matrix_with_light(color.blue, \
			ambient_light_radiance.blue, light_diffuse_radiance, \
			light_specular_reflection_radiance);
	return (radiance);
}

// 直接光の拡散反射光の放射輝度の内積 [incidence_vec 入射ベクトル], [normal 法線ベクトル]
double	_calc_light_specular_reflection_radiance_dot(t_vector ray,
													t_vector incidence_vec,
													t_vector normal)
{
	const t_vector	regular_reflection = subtraction(scale(normal, 2.0 * \
			dot_product(normal, incidence_vec)), incidence_vec);
	const t_vector	rev_ray = normalize(scale(ray, -1.0));
	double			dot;

	dot = dot_product(rev_ray, regular_reflection);
	return (constrain(dot, 0.0, 1.0));
}
