/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsishika <tsishika@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/03 04:02:38 by tsishika          #+#    #+#             */
/*   Updated: 2024/04/03 04:20:48 by tsishika         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	key_press(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		exit(0);
	}
	return (0);
}

int	close_window(t_data *data)
{
	mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	exit(0);
	return (0);
}
