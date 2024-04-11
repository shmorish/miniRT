/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:47:46 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/10 23:47:47 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_vector	scale(t_vector a, double scale)
{
	t_vector	result;

	result.x = a.x * scale;
	result.y = a.y * scale;
	result.z = a.z * scale;
	return (result);
}

t_rgb	scale_rgb(t_rgb a, double scale)
{
	t_rgb	result;

	result.red = a.red * scale;
	result.green = a.green * scale;
	result.blue = a.blue * scale;
	return (result);
}
