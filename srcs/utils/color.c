/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 23:41:18 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/10 23:46:49 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

t_rgb	integer_to_rgb(int color)
{
	t_rgb	rgb;

	rgb.red = (color >> 16) & 0xFF;
	rgb.green = (color >> 8) & 0xFF;
	rgb.blue = color & 0xFF;
	return (rgb);
}

int	trans_color(int red, int green, int blue)
{
	return ((red << 16) | (green << 8) | blue);
}

#define COLOR 255.0 /* colorの範囲 */

double	color_to_fcolor(double color)
{
	return (color / COLOR);
}
