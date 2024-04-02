/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 03:19:34 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/03 03:27:51 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	my_mlx_init(t_data *data)
{
	data->mlx = malloc(sizeof(t_mlx));
	if (data->mlx)
		print_error_and_exit("Malloc failed");
	data->mlx->mlx = mlx_init();
	data->mlx->win = mlx_new_window(data->mlx->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT,
			"miniRT");
	if (!data->mlx->win)
		print_error_and_exit("mlx_new_window failed");
	data->mlx->img_ptr = mlx_new_image(data->mlx->mlx,
			WINDOW_WIDTH,
			WINDOW_HEIGHT);
	if (!data->mlx->img_ptr)
		print_error_and_exit("mlx_new_image failed");
	data->mlx->addr = mlx_get_data_addr(data->mlx->img_ptr,
			&data->mlx->bits_per_pixel,
			&data->mlx->line_length,
			&data->mlx->endian);
}
