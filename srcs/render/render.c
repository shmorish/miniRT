/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 03:18:14 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/03 04:21:04 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static int	draw(t_data *data)
{
	int			x;
	int			y;
	t_vector	camera_ray;

	y = 0;
	while (y < WINDOW_HEIGHT)
	{
		x = 0;
		while (x < WINDOW_WIDTH)
		{
			(void)camera_ray;
			camera_ray = getCameraRay(data, x, y);
			put_pixel(data, camera_ray, x, y);
			// my_mlx_pixel_put(data->mlx, x, y, 0xE3E366);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx->mlx,
		data->mlx->win, data->mlx->img_ptr, 0, 0);
	return (0);
}

void	render(t_data *data)
{
	my_mlx_init(data);
	mlx_loop_hook(data->mlx->mlx, &draw, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->mlx->win, 17, 1L << 17, &close_window, data);
	mlx_loop(data->mlx->mlx);
}
